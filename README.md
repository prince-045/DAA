# Sorting Algorithm Profiling: Selection Sort & Insertion Sort

## Profiling Results

The following table summarizes the time taken for **Selection Sort** and **Insertion Sort** in all three cases (Best, Worst, and Average). All times are measured in **microseconds**.

| **Sorting Algorithm** | **Best Case (Sorted Array)** | **Worst Case (Reverse Sorted Array)** | **Average Case (Random Array)** |
|-----------------------|------------------------------|---------------------------------------|---------------------------------|
| **Selection Sort**     | 142 microseconds             | 259 microseconds                      | 215 microseconds                |
| **Insertion Sort**     | 48 microseconds              | 362 microseconds                      | 120 microseconds                |

### Explanation of Results:

- **Selection Sort**:
  - In the **Best Case** (Sorted Array), Selection Sort still takes a significant time (142 microseconds) due to unnecessary comparisons.
  - The **Worst Case** (Reverse Sorted Array) is the slowest for Selection Sort, with 259 microseconds.
  - The **Average Case** with a random array takes 215 microseconds.

- **Insertion Sort**:
  - In the **Best Case** (Sorted Array), Insertion Sort performs optimally with only 48 microseconds.
  - In the **Worst Case** (Reverse Sorted Array), Insertion Sort is slower, taking 362 microseconds.
  - The **Average Case** with random elements takes 120 microseconds.

## Time Complexity Summary

| **Sorting Algorithm** | **Best Case** | **Worst Case** | **Average Case** |
|-----------------------|---------------|----------------|------------------|
| **Selection Sort**     | O(n²)         | O(n²)          | O(n²)            |
| **Insertion Sort**     | O(n)          | O(n²)          | O(n²)            |
