## Activity Selection Sort Recursive
Given a set ‘S’ of ‘n’ activities, implement the recursive greedy algorithm to select a subset of activities from S by selecting the task that finishes first. Sort the activities in ascending order based on finish time and then select the activities

- Input Format
    ```
    First line contains the number of activities, n
    Next 'n' line contains the details of the activities such as name of activity, start time and finish time
    ```
- Output Format
    ```
    Print the name of the activities that are selected separated by a space
    ```

- Input:
    ```
    11
    a3 0 6
    a1 1 4
    a4 5 7
    a2 3 5
    a5 3 9
    a11 12 16
    a6 5 9
    a9 8 12
    a7 6 10
    a8 8 11
    a10 2 14
    ```

- Output:
    ```
    a1 a4 a8 a11
    ```