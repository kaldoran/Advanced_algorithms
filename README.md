Advanced_algorithms
===================

1 - Description
=============
The objective of this project is to implement some algorithms for solving Traveling Salesman Problem
(TSP) and to provide an experimental study of their running time and the quality of the outputs as
well.

2 - Work to Do
===============
You must program dierent algorithms for the TSP problem, including:
- The brute-force approach exploring all the possible solution (recursive way).
- The branch-and-bound version.
- The version adding and removing edges as seen in the exercise sheet.
- The approximation based on the minimum spanning tree as seen in the exercise sheet.
- The version considering at each step the nearest unvisited choice (called the greedy approach).
- A version based on a randomized approach.
- A version based on a genetic programming or ant colony approach.
- Optionally a personal version.

Note that all the algorithms must be able to output the solution and the corresponding length.

The running time of the algorithms and the quality of the solutions given (in terms of optimality)
have to be evaluated on problems of dierent sizes (i.e. with dierent number of cities, dierent
distances between cities, . . . ). For this purpose, you can implement a random generator able to create
automatically some TSP problems. The generator can take into account some options like the level of
sparsity of the problem (level of connectivity), a range over possible edge weights, a distribution for
generating the weights, . . .

You must also evaluate the algorithms on existing problems available on:
http://comopt.ifi.uni-heidelberg.de/software/TSPLIB95

  You must provide a rigorous experimental setup to compare the eciency of the dierent ap-
proaches and to evaluate the quality of the solutions found

  The project can be done in a group of 2 or 3 students, and each student must program at least
one algorithm.

3 - What to send
=================
  Your project must be uploaded on Claroline before Thursday 4th of December 2014
midnight, in a .zip or .tar.gz archive, well-organized. It must include the source code of the
programs and a report in pdf format. The project can be done in groups of 2 or 3 students. A project
defense is scheduled on Friday 5th of December (the exact schedule will be given later), be careful
to come to the defense with a working implementation.

  Before the defense, each group must send before Friday 24th of October 2014 midnight a
provisional planning giving the milestones of the project, with the tasks to achieve, the repartition
between the group members and the time deserved to each task. Each group must also send the
conventions that will be used to write the source code. The ability to follow the schedule will not be
taken into account for the grade, but during the defense the students must present the real planning
and discuss the reasons why the project has run late (if applicable). The quality of the presentation
(report, oral, ...) and the quality of the source code will be taken into account.

Grade scaling:
- at least 7/20 : brute-force and branch-and-bound versions must work correctly, and be evaluated
in a rigorous manner on articial data, report and source code must be presented neatly.
- at least 10/20 : each member of the group must program a dierent approach, experimental
evaluations on articial data must be rigorous, one problem of the TSP database must be used,
source code and report must be presented neatly and the answers to the questions must be
correct.
- at least 12/20 : in addition to the previous point, evaluate the algorithms on a part of the TSP
database available and implement another method (the number of methods must be higher than
the size of the group)
- at least 14/20 : in addition to the previous point, implement two new methods, and process a
signicant part of the TSP database, source code and report must be extremely neat and clear.
- at least 16/20 : program all the algorithms, process a large part of the TSP database and try to
finnd on which problem instances each method is ecient. Optionally, a graphical user interface
can be proposed.

  Note that for a given grade, the absence of one element can be compensated by the addition of an
element associated to a higher grade. Be careful, the grading scale is given for information purpose.
