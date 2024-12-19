# Sorting Algorithm Profiling: Selection Sort & Insertion Sort

## Profiling Results

The following table summarizes the time taken for **Selection Sort** and **Insertion Sort** in all three cases (Best, Worst, and Average). All times are measured in **microseconds**.

| **Sorting Algorithm** | **Best Case (Sorted Array)** | **Worst Case (Reverse Sorted Array)** | **Average Case (Random Array)** |
|-----------------------|------------------------------|---------------------------------------|---------------------------------|
| **Selection Sort**     | 142 microseconds             | 259 microseconds                      | 215 microseconds                |
| **Insertion Sort**     | 48 microseconds              | 362 microseconds                      | 120 microseconds                |

## Time Complexity Summary

| **Sorting Algorithm** | **Best Case** | **Worst Case** | **Average Case** |
|-----------------------|---------------|----------------|------------------|
| **Selection Sort**     | O(n²)         | O(n²)          | O(n²)            |
| **Insertion Sort**     | O(n)          | O(n²)          | O(n²)            |
