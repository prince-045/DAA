#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
#define INF 10000000
int minKey(const vector<int>& key, const vector<bool>& mstSet, int V) {
    int min = INF, minIndex = -1;
    for (int v = 0; v < V; ++v) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}


void primMST(const vector<vector<int>>& graph, int V) {
    vector<int> parent(V, -1); 
    vector<int> key(V, INF); 
    vector<bool> mstSet(V, false); 
    key[0] = 0; 

    auto start = chrono::high_resolution_clock::now();

    for (int count = 0; count < V - 1; ++count) {

        int u = minKey(key, mstSet, V);
        
        mstSet[u] = true; 

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] != INF && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Prim's Algorithm executed in: " << duration.count() << " microseconds" << endl;


    cout << "MST edges from Prim's Algorithm:" << endl;
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << " (Weight: " << graph[i][parent[i]] << ")" << endl;
    }
}


int findParent(int v, vector<int>& parent) {
    if (parent[v] == -1)
        return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSets(int x, int y, vector<int>& parent, vector<int>& rank) {
    int xroot = findParent(x, parent);
    int yroot = findParent(y, parent);
    
    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}


void kruskalMST(const vector<vector<int>>& graph, int V) {
    vector<pair<int, pair<int, int>>> edges;
    vector<int> parent(V, -1);
    vector<int> rank(V, 0);


    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            if (graph[i][j] != INF) {
                edges.push_back({graph[i][j], {i, j}});
            }
        }
    }

  
    sort(edges.begin(), edges.end());

    auto start = chrono::high_resolution_clock::now();

    cout << "MST edges from Kruskal's Algorithm:" << endl;
    for (auto edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        int uroot = findParent(u, parent);
        int vroot = findParent(v, parent);

  
        if (uroot != vroot) {
            cout << u << " - " << v << " (Weight: " << weight << ")" << endl;
            unionSets(uroot, vroot, parent, rank);
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Kruskal's Algorithm executed in: " << duration.count() << " microseconds" << endl;
}

int main() {
 
    int V = 5;
    vector<vector<int>> graph(V, vector<int>(V, INF));

    graph[0][1] =12;
    graph[0][2] =10;
    graph[1][2] =8 ;
    graph[1][3]=14 ;
    graph[2][3] =13;
    graph[2][4] =11;
    graph[3][4] =15;

    cout << "Prim's Algorithm:" << endl;
    primMST(graph, V);
    cout << endl;
    cout << "Kruskal's Algorithm:" << endl;
    kruskalMST(graph, V);

    return 0;
}
