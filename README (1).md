
# PREMIER LEAGUE SIMULATION

The league comprises N football teams (N<=10), numbered 1 to N. There are
total N stadiums (indexed 1 to N) and each stadium has a stadium manager. The ith
stadium is the home ground of the ith team.
Each team plays 2 games against every other team - One at its home ground and one
away (home ground of opponent team).
If a team wins a match, it gets 3 points. If it's a draw, both teams get 1 point. If a team
loses, they won't get any points.
At the end of the season, the team with the maximum points wins the premier league title.
If some teams finish with the same number of points, their position in the League table is
determined by the number of goals scored. If the teams have the same number of points
and number of goals scored, then the team with lower team index gets a higher position.

We provide the league fixture in an input file. Each line of input consists of the ids
of the teams playing the match (Refer inpuT.txt for input layout).
The aim is to  task is to schedule and simulate the matches according to the fixture given and display the final result of the league in the decreasing order of the points scored by each
team (Refer output.txt) 


## HOW TO USE:

- Run make command within the terminal which would create the executable file (final)

```bash
  make
```

- After creating the executable file type: ./final filename.txt

```bash
  ./final input-filename.txt
```

- To use given input file: 


```bash
  ./final input.txt
```



## LIST OF FILES AND THEIR FUNCTIONS:

 - main.c : The driver file, initiates creation of stadium processes through stadium.c and displays the result table through result.c. Takes name of input file as command line argument. Shared memory is created for the storage of results.

 - FOOTBALL.h: Interface file

 - stadium.c: creates stadium processes, ensures each match runs for 3 seconds then stores the result in shared memory.

 - result.c: Creates a matrix from shared memory of the results obtained from stadium.c. Then sorts the matrix according to given conditions in questions and displays the final table.


## DESCRIPTION OF STRUCTURE OF THE PROGRAM:

- main.c creates the shared memory and takes filename as command line argument.
- It then initiates stadium.c which creates the stadium processes and conducts the input matches.
- The results are stored from the matches in the created shared memory.
- main.c then initiates result.c
- The shared memory results are first converted to a 2d matrix.
- The matrix is then sorted on the given conditions in question.
- The table is then finally displayed.


## Screenshots
Input file example
[![in.png](https://i.postimg.cc/053HSRWL/in.png)](https://postimg.cc/F1yZtqQZ)
Result of the matches
[![out.png](https://i.postimg.cc/3wdtNtjK/out.png)](https://postimg.cc/DW3rYdYD)
## Authors

- [@Akshat Saxena](https://github.com/Akshat977)

