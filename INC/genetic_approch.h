//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : error.h                                        |
// DATE : 27/10/14                                          |
//                                                          |
// - Debug Maccro [C99 Convention]                          |
// - Quit maccro                                            |
//----------------------------------------------------------

#ifndef GENETIC_APPROCH
#define GENETIC_APPROCH 

/** Mutate a solution which consist in swap 2 nodes
 *  %param s : The solution which need to be mutate
 *  %return : The mutate solution
 */
Solution mutate(Solution s); 

/** Do the crossover between 2 parents with a low chance of return the parent.
 *  %param s1 : Solution 1 ( parent 1 )
 *  %param s2 : Solution 2 ( parent 2 )
 *  %return : The crossover off 2 solution
 *            Or with a small probability one off the 2 parents.
 */
Solution crossover(const Solution s1, const Solution s2);

/** Do an evolution ( with mutation and crossover ) on the array
 *  %param genetic : Array which need to be evolved
 *  %return : the evolved array
 */
Solution *evolution(const Graph g, Solution *genetic);

/** Do the genetic approch by generate random solution and evolve them
 *  %param g : Needed graph for the algorithm
 *  %retur : The best solution of the genetic_approch 
 */
Solution genetic_approch(Graph g);


#endif /* Include GENETIC_APPROCH */
