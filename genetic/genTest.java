import java.util.Random;

public class genTest
{
	//global variables:
	Population population = new Population();
	Individual fittest;
	Individual secondFittest;
	int generationCount = 0;

	public static void main(String[] args)
	{
		Random rn = new Random();

		genTest demo = new genTest();
		// create population:
		demo.population.initializePopulation();
		// get the fittness:
		demo.population.calFittness();
		// get the best fittness in population:
		System.out.println("generation: "+demo.generationCount+"fittest "+demo.population.getFittest().fitness);
		
		// Population demo = new Population();
		// System.out.println(demo.getFittest().fitness); //before calculate
		// demo.calFittness();
		// System.out.println(demo.getFittest().fitness); //after calcaulate
		// while(demo.population.fittest < 5){

		// }
		while (demo.population.m_fittest < 5) {
            ++demo.generationCount;

            demo.selection();
			demo.crossover();
            
            //Do mutation under a random probability
            if (rn.nextInt()%7 < 5) {
                demo.mutation();
            }
            
            //Add fittest offspring to population
            demo.addFittestOffspring();
            
            //Calculate new fitness value 
            demo.population.calFittness();
            
            System.out.println("Generation: " + demo.generationCount + " Fittest: " + demo.population.m_fittest);
        }

        System.out.println("\nSolution found in generation " + demo.generationCount);
        System.out.println("Fitness: "+demo.population.getFittest().fitness);
        System.out.print("Genes: ");
        for (int i = 0; i < 5; i++) {
            System.out.print(demo.population.getFittest().genes[i]);
        }

        System.out.println("");
		
	}

	//Selection operation:
	void selection(){
		//select the best fittness individual:
		fittest = population.getFittest();

		for (int i=0;i< fittest.genes.length;i++){
			System.out.print(fittest.genes[i]+" ");
		}
		System.out.println();
		//select teh second Fittness individual:
		secondFittest = population.getSecondFittest();

		for (int i=0;i< fittest.genes.length;i++){
			System.out.print(secondFittest.genes[i]+" ");
		}
		System.out.println();
	}

	void crossover(){
		Random rn = new Random();
		// select a random mutation point: 
		int crossoverPoint = rn.nextInt(population.m_individual[0].genesLength);
		System.out.println(crossoverPoint);

		for (int i=0; i<crossoverPoint;i++){
			int tmp = fittest.genes[i];
			fittest.genes[i] = secondFittest.genes[i];
			secondFittest.genes[i] = tmp;
		}
	}

	void mutation(){
		Random rn = new Random();

		int mutationPoint = rn.nextInt(population.m_individual[0].genesLength);

		// flip values at the mutation point:
		if (fittest.genes[mutationPoint]==0){
			fittest.genes[mutationPoint]=1;
		}else{
			fittest.genes[mutationPoint]=0;
		}

		for (int i=0;i< fittest.genes.length;i++){
			System.out.print(fittest.genes[i]+" ");
		}
		System.out.println();

		mutationPoint = rn.nextInt(population.m_individual[0].genesLength);

		if (secondFittest.genes[mutationPoint]==0){
			secondFittest.genes[mutationPoint]=1;
		}else{
			secondFittest.genes[mutationPoint]=0;
		}

		for (int i=0;i< fittest.genes.length;i++){
			System.out.print(secondFittest.genes[i]+" ");
		}
		System.out.println();
	}

	//Get fittest offspring
    Individual getFittestOffspring() {
        if (fittest.fitness > secondFittest.fitness) {
            return fittest;
        }
        return secondFittest;
    }


    //Replace least fittest individual from most fittest offspring
    void addFittestOffspring() {
        
        //Update fitness values of offspring
        fittest.calcFitness();
        secondFittest.calcFitness();
        
        //Get index of least fit individual
        int leastFittestIndex = population.getLeastFittestIndex();
        
        //Replace least fittest individual from most fittest offspring
        population.m_individual[leastFittestIndex] = getFittestOffspring();
    }

}
