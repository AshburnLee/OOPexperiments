class Population
{

    private int m_popSize = 20;
    Individual[] m_individual = new Individual[m_popSize];  //class attribute!
    int m_fittest = 0;
	
	public Population(){
		
		System.out.println(m_popSize+" Population()");
	}

	public void initializePopulation(){
		// /init
		for(int i=0; i<m_individual.length;i++){
			m_individual[i] = new Individual();   //init 3 individuals
		}
	}

    public void calFittness(){
        for(int i=0;i<m_individual.length;i++){
            m_individual[i].calcFitness();
        }
        getFittest();
    }

	public Individual getFittest() {
        int maxFit = Integer.MIN_VALUE;    //?
        for (int i = 0; i < m_individual.length; i++) {
            if (maxFit <= m_individual[i].fitness) {
                maxFit = i;
            }
        }
        m_fittest = m_individual[maxFit].fitness;
    	return m_individual[maxFit];
    }

        //Get the second most fittest individual
    public Individual getSecondFittest() {
        int maxFit1 = 0;
        int maxFit2 = 0;
        for (int i = 0; i < m_individual.length; i++) {
            if (m_individual[i].fitness > m_individual[maxFit1].fitness) {
                maxFit2 = maxFit1;
                maxFit1 = i;
            } else if (m_individual[i].fitness > m_individual[maxFit2].fitness) {
                maxFit2 = i;
            }
        }
        return m_individual[maxFit2];
    }

    public int getLeastFittestIndex(){
        int minFit = 0;
        for(int i=0; i<m_individual.length; i++){
            if(minFit >= m_individual[i].fitness){
                minFit = i;
            }
        }
        return minFit;
    }

}
