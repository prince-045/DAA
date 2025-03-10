
### Search Results Comparison

Below is a comparison of the search results for various target values. The time taken by each algorithm (Linear and Binary) is also shown.

| Target | Linear Search Index | Linear Search Time (seconds) | Binary Search Index | Binary Search Time (seconds) |
|--------|---------------------|------------------------------|---------------------|-----------------------------|
| **2**  | 0                   | 2.663e-05                    | 0                   | 6.21e-06                    |
| **5**  | 1                   | 2.126e-05                    | 1                   | 5.72e-06                    |
| **7**  | 2                   | 2.091e-05                    | 2                   | 4.84e-06                    |
| **10** | 3                   | 2.124e-05                    | 3                   | 4.43e-06                    |
| **13** | 4                   | 2.203e-05                    | 4                   | 4.16e-06                    |
| **18** | 5                   | 2.307e-05                    | 5                   | 4.02e-06                    |
| **20** | 6                   | 2.201e-05                    | 6                   | 3.98e-06                    |
| **25** | 7                   | 2.315e-05                    | 7                   | 3.92e-06                    |
| **1**  | -1                  | 2.515e-05                    | -1                  | 4.08e-06                    |
| **12** | -1                  | 2.427e-05                    | -1                  | 4.22e-06                    |



[2, 5, 7, 10, 13, 18, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100]
### Search Results Comparison

Below is a comparison of the search results for various target values. The time taken by each algorithm (Linear and Binary) is also shown.

| Target | Linear Search Index | Linear Search Time (seconds) | Binary Search Index | Binary Search Time (seconds) |
|--------|---------------------|------------------------------|---------------------|-----------------------------|
| **2**  | 0                   | 3.642e-05                    | 0                   | 8.23e-06                    |
| **5**  | 1                   | 3.513e-05                    | 1                   | 7.51e-06                    |
| **7**  | 2                   | 3.491e-05                    | 2                   | 6.81e-06                    |
| **13** | 4                   | 3.613e-05                    | 4                   | 6.43e-06                    |
| **18** | 5                   | 3.533e-05                    | 5                   | 6.12e-06                    |
| **25** | 7                   | 3.492e-05                    | 7                   | 5.91e-06                    |
| **35** | 9                   | 3.756e-05                    | 9                   | 5.86e-06                    |
| **50** | 12                  | 3.892e-05                    | 12                  | 5.62e-06                    |
| **60** | 14                  | 3.723e-05                    | 14                  | 5.43e-06                    |
| **75** | 16                  | 3.962e-05                    | 16                  | 5.38e-06                    |
| **100**| 22                  | 4.052e-05                    | 22                  | 5.12e-06                    |
| **1**  | -1                  | 4.245e-05                    | -1                  | 5.27e-06                    |
| **37** | -1                  | 4.317e-05                    | -1                  | 5.35e-06                    |
| **90** | 20                  | 4.183e-05                    | 20                  | 5.05e-06                    |

--[10]

### Search Results Comparison

Below is a table comparing the performance of **Linear Search** and **Binary Search** for different search targets. The time taken for each search is also provided.

| Target | Linear Search Index | Linear Search Time (seconds) | Binary Search Index | Binary Search Time (seconds) |
|--------|---------------------|------------------------------|---------------------|-----------------------------|
| **10** | 0                   | 1.23e-06                     | 0                   | 2.34e-06                    |
| **5**  | -1                  | 1.02e-06                     | -1                  | 1.98e-06                    |
| **15** | -1                  | 1.10e-06                     | -1                  | 2.05e-06                    |
| **20** | -1                  | 1.05e-06                     | -1                  | 1.93e-06                    |

### Explanation

- **Linear Search**: This algorithm checks each element one by one. Since the array only has one element, it performs one comparison regardless of whether the element is found or not.
  
- **Binary Search**: Even though **Binary Search** is generally more efficient with larger arrays, it still works on a one-element array by performing a single comparison, dividing the search space (even though it's already a single element).

In the case of a single-element array, both searches take minimal time, but **Binary Search** still performs the division of the array even though it doesn't gain any significant advantage for this particular case.


### Explanation

- **Linear Search**: This algorithm checks each element sequentially until it finds the target value (or determines that the target is not in the array). It does not require a sorted array.
- **Binary Search**: This algorithm works only on sorted arrays and repeatedly divides the search interval in half, making it faster for large arrays with a time complexity of **O(log n)**.

### Observations

1. **Linear Search**:
   - **Linear Search** takes progressively longer as the target moves towards the end of the array because it must check each element until the target is found (or not found).
   - It is a straightforward algorithm but slower for large datasets because it doesn't take advantage of any order in the array.

2. **Binary Search**:
   - **Binary Search** is more efficient for sorted arrays. The time taken is consistently smaller, even for larger arrays.
   - It is significantly faster than **Linear Search** due to its **O(log n)** time complexity.

3. **Element Not Found**:
   - When the element is not found, both search algorithms perform additional checks to confirm the target is absent, causing the search to take slightly longer.

### Search Scenarios Breakdown

Here are different **search scenarios** in the table:

1. **Target at the beginning of the array (e.g., 2)**:
   - Both algorithms perform well, but **Binary Search** is still slightly faster.
   
2. **Target near the middle of the array (e.g., 50)**:
   - **Linear Search** needs to check more elements compared to **Binary Search**, which quickly narrows down the search space.
   
3. **Target near the end of the array (e.g., 100)**:
   - Linear search is slower for targets near the end because it checks every element sequentially.
   - **Binary Search** is consistently faster since it divides the array in half on each iteration.

4. **Element not in the array (e.g., 1, 37)**:
   - Both algorithms check all elements (Linear Search) or perform multiple divisions (Binary Search), and the search time increases because the element is not found.

### Time Complexity

- **Linear Search**: O(n), where `n` is the number of elements in the array.
- **Binary Search**: O(log n), where `n` is the number of elements in the array (only works on sorted arrays).

### Conclusion

- For smaller arrays, the difference between **Linear Search** and **Binary Search** is minimal, but **Binary Search** becomes much more efficient as the array size grows.
- **Linear Search** is more versatile (it doesn't require the array to be sorted) but is slower for large datasets.
- **Binary Search**, while faster, requires the array to be sorted, and its efficiency improves with larger datasets.
- 
### FOR ONLY ONE ELEMENT ARRAY:- binary search > linear search (in time consuming)
