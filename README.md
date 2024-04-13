The program utilized polymorphism for the sake of clarity within the Hill Climbing algorithm, where the virtual method generateNeighbor() was invoked. If you want to add additional custom classes for generating neighbors, you can easily do so by adding a new class that inherits from NeighborGenerator and making a simple adjustment to the constructor of HillClimb.

To run the program:
```
make
./sudoku
```

# The "Sudoku Solver" 
project was created as a semester assignment for the course BI-ZUM


## BI-ZUM
The subject provides a basic introduction to the study of artificial intelligence with an emphasis on symbolic techniques. Classic areas such as state space search, heuristic search, agent systems, game decision-making, automatic planning, robotics, and task modeling will be covered.

### Assignment
[EN] Formulate SUDOKU as a local search problem, i.e., in terms of a hill-climbing algorithm.
Try out various variants of locally changing the candidate for a solution and compare them.
A 9x9 grid is child's play for today's computers (of course, depending on the context), so try out generalized SUDOKU on a larger playing field.