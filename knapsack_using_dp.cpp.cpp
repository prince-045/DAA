#include<iostream>
#include<algorithm>
#include<vector>
#include<chrono>

using namespace std;

void fractionalKnapsack(vector<int>& a, vector<int>& b, vector<int>& c) {
    int memory = 0;  
    int cost = 0;    
    int capacity = 20;  
    int remaining;   

    for (int i = 0; i < 5; i++) {
        a[i] = b[i] / c[i];
    }

    vector<pair<int, int>> items; 
    for (int i = 0; i < 5; i++) {
        items.push_back({a[i], i});
    }
    sort(items.rbegin(), items.rend());  

    for (int i = 0; i < 5; i++) {
        int idx = items[i].second;
        if (memory + c[idx] <= capacity) {
            memory += c[idx];
            cost += b[idx];
        } else {
            remaining = capacity - memory;
            cost += remaining * a[idx];  
            break;  
        }
    }

    cout << "Fractional Knapsack Total Cost: " << cost << endl;
}


int zeroOneKnapsack(int capacity, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    vector<int> a(5); 
    vector<int> b{50, 30, 20, 40, 10}; 
    vector<int> c{6, 10, 8, 8, 5};  
    int capacity = 20;

  
    auto start_fractional = chrono::high_resolution_clock::now();
    fractionalKnapsack(a, b, c);
    auto end_fractional = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_fractional = end_fractional - start_fractional;
    cout << "Fractional Knapsack Execution Time: " << duration_fractional.count() << " seconds" << endl;


    auto start_01 = chrono::high_resolution_clock::now();
    int result_01 = zeroOneKnapsack(capacity, c, b); 
    auto end_01 = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_01 = end_01 - start_01;
    cout << "0/1 Knapsack Total Cost: " << result_01 << endl;
    cout << "0/1 Knapsack Execution Time: " << duration_01.count() << " seconds" << endl;

    return 0;
}
