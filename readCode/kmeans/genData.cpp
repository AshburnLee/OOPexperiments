// This file generates random 2D points and saves them in a binary file.
// To run the code you need to provide:
// 1. number of clusters, 
// 2. number of points, and
// 3. points' maximum value. 
// The output binary file is created in the local directory,
// and it is named 2DPoints_#ofpoints_C_#ofclusters.data

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maxRange;   //input by keyboard

void genRand1DPoints(const char* buffer, int points_num,int centroid_num )
{
  /* initialize random seed: */
  srand(time(NULL));
  //allocate heap mem
  float* points_ptr = new float[points_num];     //# of points
  float* centroid_ptr = new float[centroid_num];   //# of centroids


  //generate random number from (0~maxRange-1)
  for (int i = 0; i < centroid_num; i++)  //for each centroid
    centroid_ptr[i] = rand() % maxRange; 

  
  //Algorithm to generate points:!!
  for (int i = 0 ; i < points_num; i++){  //for each points
    int c = rand() % centroid_num;        //choose a centroid 	  
    points_ptr[i] = centroid_ptr[c] + rand()%2; 
  }


  //print centroids:
  printf("random chosen centers: \n");
  for (int i = 0 ; i < centroid_num; i++)
    printf("center %d: %f\n", i, centroid_ptr[i]);
  printf("\n");

  //print points:
  for(int i=0;i<points_num;i++){
    printf("%f ",points_ptr[i]);
    printf("\n");
  }

  //file opt:
  FILE* fp = fopen(buffer, "wb");  //"wb"
  fwrite(points_ptr, sizeof(float), points_num, fp);
  fclose(fp); 

  delete[] centroid_ptr; 
  delete[] points_ptr;   
}



void genRand2DPoints(const char* buffer, int points_num,int centroid_num ){
  srand(time(NULL));
  float* points_ptr = new float[2*points_num]; 
  float* centroid_ptr = new float[2*centroid_num];
  
  // pick random points as cluters centers
  for (int i = 0; i < centroid_num; i++){
    centroid_ptr [2*i] = rand() % maxRange; 
    centroid_ptr [2*i+1] = rand() % maxRange; 
  }
  // generate random points 

  for (int i = 0 ; i < points_num; i++){
    int c = rand() % centroid_num; 	  
    points_ptr[2*i] = rand() % 2 + centroid_ptr[2*c];; 
    points_ptr[2*i+1] = rand() % 2 + centroid_ptr[2*c+1];; 
  }

  printf("random chosen centers: \n");   // not quite the cluster centers
  for (int i = 0 ; i < centroid_num; i++)
    printf("center %d: %f %f\n", i, centroid_ptr[2*i], centroid_ptr[2*i+1]);
  printf("\n");

  for (int i = 0 ; i < points_num; i++)
    printf("points %d: %f %f\n", i, points_ptr[2*i], points_ptr[2*i+1]);

  // write points in a binary file
  FILE* fp = fopen(buffer, "wb"); //"wb"
  fwrite(points_ptr, sizeof(float), 2*points_num, fp);
  fclose(fp); 

  delete[] centroid_ptr; 
  delete[] points_ptr;   
}


int main(int argc, char ** argv){

  if (argc < 4){
    printf("Provide\n\t1)number of clusters\n\t2)number of points\n\t3)Max range value\n");
    return 0; 
  }

  int centroid_num = atoi(argv[1]);   //# of centroid
  int points_num = atoi(argv[2]);   //# of points
  maxRange = atoi(argv[3]);  //# max range value

  if (centroid_num > points_num){
   printf("Nr of clusters should be smaller than number of points");
   return 0; 
  }

  char buffer[40];  
//  sprintf(buffer, "Points_%d_C_%d.data", points_num, centroid_num);
//  genRand1DPoints(buffer, points_num, centroid_num);

  sprintf(buffer, "2DPoints_%d_C_%d.data", points_num, centroid_num);
  genRand2DPoints(buffer, points_num, centroid_num);

}
