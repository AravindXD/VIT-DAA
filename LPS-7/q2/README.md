## Matching String Categorization
Given a text T of length n and a string P of length m, categorize substrings of T that begin at index s (where 0 ≤ s ≤ n-m) into "Matching", "First match increasing", "First match decreasing" and "Not matching" . 

    1. Matching if T[s+1..s+m] = P[1..m]

    2. First match increasing if Inc(T[s+1..s+m], P[1..m]),where Inc is a function that returns true if T[s+1] = P[1] and T[s+i] - P[i] > T[s+i-1] - P[i-1] for 2 ≤ i ≤ n-m

    3. First match decreasing if Dec(T[s+1..s+m], P[1..m]), where Inc is a function that returns true if T[s+1] = P[1] and T[s+i] - P[i] < T[s+i-1] - P[i-1] for 2 ≤ i ≤ n-m

    4. Not matching - If none of the above cases is satisfied

For example, if T = "aabcacd" and P = "abc" then print 

First match decreasing - Dec(aab, abc) will return true

Matching - abc, abc matches

Not matching - bca, abc not matching

Not matching - cac, abc not matching

First match Increasing - Inc(acd, abc) will return true

- Input Format
    ```
    First line contains the text, T

    Next line contains the pattern, P
    ```
- Output Format
    ```
    For every index 0≤i≤n-m, Print Matching, First match Increasing, First match decreasing or Not matching
    ```