import java.util.Random;


class Individual

{
	int genesLength = 5;
	int[] genes = new int[genesLength];
	int fitness = 0;

	public Individual(){   //constructor, no return type!!
		Random rn = new Random();
		
		for (int i=0;i<genes.length;i++){
			genes[i] = rn.nextInt()%4;  //(-4, 4)
			System.out.print(genes[i]+" ");
		}
		System.out.println();

	}

	public void calcFitness(){
		for(int i=0;i<genes.length;i++){
			if(genes[i]==1){
				++fitness;
			}
		}
		System.out.println("fitness: "+fitness);
	}
}
