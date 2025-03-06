#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the maximum value using DP
int knapsackDP(const vector<int>& weights, const vector<int>& values, int W, int n, vector<vector<int>>& dp) {
    // Fill the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; // No item or no capacity
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w]; // Skip the item
            }
        }
    }
    return dp[n][W]; // Return the maximum value
}

// Function to print all possible solutions and the optimal solution
void printSolutions(const vector<int>& weights, const vector<int>& values, int W, int n, vector<vector<int>>& dp) {
    vector<int> includedItems;
    int w = W;
    
    // Backtrack to find all possible solutions
    while (n > 0 && w > 0) {
        if (dp[n][w] != dp[n - 1][w]) {  // If the item is included
            includedItems.push_back(n - 1);
            w -= weights[n - 1];
        }
        n--;
    }

    // Print the optimal solution (included items)
    cout << "Optimal Solution (101 10 format): ";
    vector<int> solution(W + 1, 0);
    for (int i : includedItems) {
        solution[weights[i]] = 1;  // Mark included item weights
    }

    for (int i = 0; i <= W; i++) {
        cout << solution[i] << " ";
    }
    cout << endl;

    // Print all possible solutions
    cout << "All possible solutions (with max value " << dp[weights.size()][W] << "):\n";
    for (int i = 0; i < (1 << weights.size()); i++) {
        vector<int> itemsInCurrentSolution;
        int currentWeight = 0;
        int currentValue = 0;
        for (int j = 0; j < weights.size(); j++) {
            if ((i >> j) & 1) {  // If the j-th item is included
                itemsInCurrentSolution.push_back(j);
                currentWeight += weights[j];
                currentValue += values[j];
            }
        }
        // If weight is within the limit and value is optimal
        if (currentWeight <= W && currentValue == dp[weights.size()][W]) {
            cout << "Solution: ";
            for (int item : itemsInCurrentSolution) {
                cout << item << " ";
            }
            cout << "| Weight: " << currentWeight << " Value: " << currentValue << endl;
        }
    }
}

int main() {
    int n, W;
    
    // Input
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter maximum weight capacity of the knapsack: ";
    cin >> W;

    vector<int> weights(n), values(n);
    
    cout << "Enter weights and values of the items:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> weights[i];
        cout << "Item " << i + 1 << " - Value: ";
        cin >> values[i];
    }

    // DP Table to store solutions
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    // Call the knapsack function
    int maxValue = knapsackDP(weights, values, W, n, dp);
    cout << "Maximum Value: " << maxValue << endl;

    // Print all solutions and the optimal solution
    printSolutions(weights, values, W, n, dp);

    return 0;
}
