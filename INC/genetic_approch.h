#ifndef GENETIC_APPROCH
#define GENETIC_APPROCH 

Solution mutate(Solution s); 

Solution crossover(const Solution s1, const Solution s2);

Solution *evolution(Solution *genetic);

Solution genetic_approch(Graph g);


#endif /* Include GENETIC_APPROCH */
