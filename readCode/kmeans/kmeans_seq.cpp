// COMP5811M, CW2
// a sequential implementation of the K-means algorithm in C++

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int maxItrNr = 100; 

 
struct Point2D{
  float x;
  float y;
};


int readPoints(const char * fn, int pNr,  Point2D * ps){
  FILE * fp = fopen(fn, "rb");    // open a binary input file to read data from  
  if (fp == NULL) return 0;      
  int tmp = fread(ps, sizeof(float), 2*pNr, fp);  // binary read 
  fclose(fp);                      
  return tmp;                     // return the number of successfully read elements 
}

// Prints centroids' coordinates on standard output.
// If "details" flag is true, more details including 
// points assigned to each cluster are printed too
void printClustres(int cNr, int pNr, const Point2D * cs, Point2D * ps, const int * p2cs, bool details){
  for (int i = 0; i < cNr; i++)
    printf("center %d: %f %f\n", i, cs[i].x, cs[i].y);
  
  if (details){
    printf ("\n------------------- details --------------------------\n");
    for (int i = 0; i < cNr; i++){
      printf("center %d: %f %f\n", i, cs[i].x, cs[i].y);
      printf( "Points: \n");
      int k = 0; 
      for (int j = 0; j < pNr; j++){
        if (p2cs[j] == i){
          switch (k){
            case 8 : printf ("\n(%.3f,%.3f)\t",  ps[j].x, ps[j].y);
                   break; 
            default: printf ("(%.3f,%.3f)\t",  ps[j].x, ps[j].y);
          }
          k = (k == 8) ? 0: k+1; 
        } 
      }
      printf("\n");
    }  
  }
}

// Initialize cluster centroids to the first K points from the dataset 
void initializeClusters(int n, Point2D const * ps, Point2D * ctds){
  for (int i = 0; i < n; i++){
    ctds[i].x = ps[i].x; 
    ctds[i].y = ps[i].y; 
  }
} 

// Assign each point to the cluster whose mean has 
// the least squared Euclidean distance, i.e. to the "nearest" mean
void assignClusters(int pNr, Point2D const *ps, int cNr, Point2D const * ctds, int * p2cs){
  float cdis;
  int cIdx;
  int tmp, tmp_x, tmp_y; 
  for (int p = 0; p < pNr; p++){
    // minimum distanse is set to the distance to the first cluster 
    tmp_x = ps[p].x - ctds[0].x;
    tmp_y = ps[p].y - ctds[0].y;
    cdis = tmp_x * tmp_x + tmp_y * tmp_y; 
    cIdx = 0; 
    // iterate over all centroids, to find the closest one
    for (int c  = 1; c < cNr; c++){
      tmp_x = ps[p].x - ctds[c].x;
      tmp_y = ps[p].y - ctds[c].y;
      tmp = tmp_x*tmp_x + tmp_y*tmp_y; 
      if ( cdis > tmp){   
        cdis = tmp; 
        cIdx = c;  
      }
    }
    // assign this point to the cluster with minimum distance 
    p2cs[p] = cIdx; 
  }
}

// Update centroids of all clusters
void centroids(int pNr, Point2D const * ps, int cNr, const int * p2cs, Point2D * ctds){
  int * counters = new int [cNr];
  memset(counters, 0, cNr * sizeof(int));
  for (int i = 0; i < cNr; i++)
    ctds[i].x = ctds[i].y = 0;
  int tmp; 
  // For each cluster, sum the coordintates of 
  // all points which have been assigned to it 
  for (int p = 0; p < pNr; p++){
    tmp = p2cs[p];
    ctds[tmp].x += ps[p].x;
    ctds[tmp].y += ps[p].y;
    counters[tmp]++;            
  } 
  // compute the mean by dividing the sum of coordinates 
  // with the number of points
  for (int i = 0; i < cNr; i++){
    if (counters[i] > 0){
       ctds[i].x = ctds[i].x / counters[i];
       ctds[i].y = ctds[i].y / counters[i];
    }else{
       // if no points are assigned to this cluster,
       // choose a point from dataset randomly to be 
       // the new centroid
       tmp = rand() % pNr ; 
       ctds[i].x = ps[tmp].x; 
       ctds[i].y = ps[tmp].y; 
    }
    
  }
  delete [] counters;
} 


int main (int argc, char ** argv){
  
  if (argc < 2){
    printf("Provide the address of input data file.\n");
    return 0; 
  }
  int pNr; 
  int cNr; 

  // Extract # of points and # of clusters 
  // from the name of the input file 
  if (sscanf(argv[1], "2DPoints_%d_C_%d.data", &pNr, &cNr) != 2){
    printf("Error! Unexpected file name.\n");
    return 0; 
  }
  printf("Number of Points: %d\nNumber of Clusters: %d\n", pNr, cNr); 
  // On host, allocate memory for 
  // 1. points 
  // 2. cluster centers 
  Point2D * ps = new Point2D[pNr];
  Point2D * cs = new Point2D[cNr];
  int * p2cMap = new int [pNr]; 

  // Read observed points from the input file 
  if (readPoints(argv[1], pNr, ps) == 0)
   printf("Error! Unable to open input file.");
 
  // Initalize the cluster centroids 
  initializeClusters(cNr, ps, cs);

  // Iteratively proceed by alternating between two steps
  // 1. assignment step, 2. update centroids
  for (int i =0; i < maxItrNr; i++){
    assignClusters( pNr, ps, cNr, cs, p2cMap);
    centroids(pNr, ps, cNr, p2cMap, cs);
  }

  printClustres(cNr, pNr, cs, ps, p2cMap, false);

  delete [] p2cMap;  
  delete [] cs;
  delete [] ps; 
}
