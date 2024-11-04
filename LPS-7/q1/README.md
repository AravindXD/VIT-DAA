## Naive string matching without Overlapping
Given a text T and a pattern P, implement the naive algorithm to print the non-overlapping positions of P in T. For example, if T is "aaaaaaaa" and pattern is "aa" then the code should print 0, 2, 4, 6 (programming indices - non-over lapping)

- Input Format
    ```
    First line contains the text, T
    Next line contains the pattern, P
    ```
- Output Format
    ```
    Print non-overlapping indices, one value in one line
    ```

- Example:

    - Input:
        ```
        aaaaaaaa
        aa
        ```
    - Output:
        ```
        0
        2
        4
        6
        ```