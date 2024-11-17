## [Move Diagonal Hate 3 Queen Game](soln.cpp)
Move Diagonal Hate 3 Queen Game is a board game in which we have to place min(m,n) queens on a mXn rectangular board. The rows and columns are numbered from 1 to m and 1 to n respectively. We cannot place a queen on a cell if sum of their row and column indices is divisible by 3 (i.e) queens cannot be placed on cells with indices like (1,2), (5,1), ... In this game a queen is attacked by another queen if they are on the same row or on the same column. For example, if the dimension of the rectangular board is 4X5 then one of the solution is:

1 0 0 0 0 
0 1 0 0 0 
0 0 0 1 0 
0 0 1 0 0

There are 6 such possible solutions for this board dimension. Given the dimension of the rectangular board develop a recursive algorithm using backtracking technique to find the number of different solutions

- Input Format
    ```
    First line contains number of rows in the rectangular board, m
    Next line contains number of rows in the rectangular board, n
    ```
- Output Format
    ```
    Print the number of solutions
    ```