#include <iostream>
#include <vector>
#include <algorithm>  // For binary search
#include <chrono>     // For profiling time

using namespace std; // To avoid needing to use std:: before standard types

// Function for Linear Search
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << "Linear Search: Checking index " << i << " (Value: " << arr[i] << ")" << endl;
        if (arr[i] == target) {
            return i;  // Return the index if the element is found
        }
    }
    return -1;  // Return -1 if element is not found
}

// Function for Binary Search
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        cout << "Binary Search: Left = " << left << ", Right = " << right << ", Mid = " << mid << " (Value: " << arr[mid] << ")" << endl;

        // Check if the target is at mid
        if (arr[mid] == target) {
            return mid;  // Return the index if found
        }

        // If the target is smaller, ignore the right half
        if (arr[mid] > target) {
            right = mid - 1;
        }
        // If the target is larger, ignore the left half
        else {
            left = mid + 1;
        }
    }
    return -1;  // Return -1 if element is not found
}

int main() {
    // Example array
    vector<int> arr = {2, 5, 7, 10, 13, 18, 20, 25};

    int target;
    cout << "Enter the number to search: ";
    cin >> target;

    // Linear Search profiling
    auto start = chrono::high_resolution_clock::now();
    int linearResult = linearSearch(arr, target);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> linearDuration = end - start;

    if (linearResult != -1) {
        cout << "Linear Search: Found " << target << " at index " << linearResult << endl;
    } else {
        cout << "Linear Search: " << target << " not found" << endl;
    }
    cout << "Linear Search took: " << linearDuration.count() << " seconds." << endl;

    // Binary Search profiling (Array must be sorted for binary search)
    start = chrono::high_resolution_clock::now();
    int binaryResult = binarySearch(arr, target);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> binaryDuration = end - start;

    if (binaryResult != -1) {
        cout << "Binary Search: Found " << target << " at index " << binaryResult << endl;
    } else {
        cout << "Binary Search: " << target << " not found" << endl;
    }
    cout << "Binary Search took: " << binaryDuration.count() << " seconds." << endl;

    return 0;
}
