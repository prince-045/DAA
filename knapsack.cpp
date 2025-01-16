
#include<iostream>
#include<algorithm>
#include<vector>
#include<chrono>

using namespace std;

void knapsack(vector<int>& a, vector<int>& b, vector<int>& c) {
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

    /
    cout << "Total cost: " << cost << endl;
}

int main() {
    vector<int> a(5); 
    vector<int> b{50, 30, 20, 40, 10};  
    vector<int> c{6, 10, 8, 8, 5};  

    auto start = chrono::high_resolution_clock::now();
    
    knapsack(a, b, c);
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    
    
    cout << "Execution Time: " << duration.count() << " seconds" << endl;

    return 0;
}
