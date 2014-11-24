#ifndef GENETIC_APPROCH
#define GENETIC_APPROCH 

void mutate(Solution s); 

Solution crossover(const Solution s1, const Solution s2);

int contains(Solution s, Node n); 
void evolution(Solution *genetic);

void genetic_approch(Graph g);


#endif /* Include GENETIC_APPROCH */
