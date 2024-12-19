#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

// Function to perform Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Function to perform Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Function to generate a random vector of integers
vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000; // Generate random numbers between 0 and 999
    }
    return arr;
}

// Function to generate a sorted vector of integers (Best case)
vector<int> generateSortedArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = i;
    }
    return arr;
}

// Function to generate a reverse sorted vector of integers (Worst case)
vector<int> generateReverseSortedArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = size - i - 1;
    }
    return arr;
}

int main() {
    int size = 1000; // Change the size as needed for profiling
    srand(time(0));

    // Best case: Sorted array
    vector<int> bestCaseArray = generateSortedArray(size);

    // Worst case: Reverse sorted array
    vector<int> worstCaseArray = generateReverseSortedArray(size);

    // Average case: Random array
    vector<int> avgCaseArray = generateRandomArray(size);

    // Profiling Selection Sort for Best Case
    vector<int> selectionBest = bestCaseArray;
    auto start = high_resolution_clock::now();
    selectionSort(selectionBest);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Selection Sort - Best Case (Sorted Array): " << duration.count() << " microseconds" << endl;

    // Profiling Selection Sort for Worst Case
    vector<int> selectionWorst = worstCaseArray;
    start = high_resolution_clock::now();
    selectionSort(selectionWorst);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Selection Sort - Worst Case (Reverse Sorted Array): " << duration.count() << " microseconds" << endl;

    // Profiling Selection Sort for Average Case
    vector<int> selectionAvg = avgCaseArray;
    start = high_resolution_clock::now();
    selectionSort(selectionAvg);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Selection Sort - Average Case (Random Array): " << duration.count() << " microseconds" << endl;

    // Profiling Insertion Sort for Best Case
    vector<int> insertionBest = bestCaseArray;
    start = high_resolution_clock::now();
    insertionSort(insertionBest);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Insertion Sort - Best Case (Sorted Array): " << duration.count() << " microseconds" << endl;

    // Profiling Insertion Sort for Worst Case
    vector<int> insertionWorst = worstCaseArray;
    start = high_resolution_clock::now();
    insertionSort(insertionWorst);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Insertion Sort - Worst Case (Reverse Sorted Array): " << duration.count() << " microseconds" << endl;

    // Profiling Insertion Sort for Average Case
    vector<int> insertionAvg = avgCaseArray;
    start = high_resolution_clock::now();
    insertionSort(insertionAvg);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Insertion Sort - Average Case (Random Array): " << duration.count() << " microseconds" << endl;

    return 0;
}
