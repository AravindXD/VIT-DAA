<h1 style="color:red;text-align:right">Aravind N 22BRS1099</h1>

# Lab-6: Longest Common Subsequence

## [Q1. LCS to print length](q1/soln.cpp)
[Question.](q1/README.md)

- The time complexity of this LCS algorithm is O(m × n), where m and n are the lengths of the two input strings.
- The space complexity is optimized to O(n) by maintaining only two rows of the DP table.

[View Interactive Plot](https://aravindxd.github.io/VIT-DAA/LPS6-q1.html)

The plot shows:
- A 3D scatter plot with points representing actual measurements.
- The x-axis represents the length of string 1 (m), the y-axis represents the length of string 2 (n), and the z-axis represents the computation time in microseconds.
- The color gradient of points indicates the execution time, with darker colors representing shorter times and brighter colors representing longer times.
- The overall trend shows an increase in computation time as both m and n increase, which aligns with the expected O(m × n) time complexity.

## [Q2. Print all LCSs](q2/soln.cpp)
[Question.](q2/README.md)
- The time complexity for printing all LCSs can be exponential in the worst case, as there can be exponentially many longest common subsequences.
- The base complexity for constructing the DP table remains O(m × n).

[View Interactive Plot](https://aravindxd.github.io/VIT-DAA/LPS6-q2.html)

The plot demonstrates:
- A 3D scatter plot showing the relationship between the lengths of two input strings (m and n) and the computation time.
- The z-axis uses a logarithmic scale for time, which helps visualize the potentially exponential growth in computation time for certain inputs.
- The color gradient represents the execution time, with darker colors for shorter times and brighter colors for longer times.
- The plot shows a more dramatic increase in computation time compared to Q1, especially for larger input sizes, which is consistent with the potential for exponential time complexity when generating all LCSs.

These visualizations help illustrate the performance characteristics of the LCS algorithms, showing how computation time scales with input size and highlighting the difference between finding the length of LCS (Q1) and generating all possible LCSs (Q2).
