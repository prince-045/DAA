#include <iostream>
#include <vector>
#include <climits>
#include <chrono>
#include <queue>

using namespace std;
using namespace std::chrono;
struct Edge {
    int dest;
    int weight;
};


void dijkstra(int V, vector<vector<Edge>>& graph, int start) {
    vector<int> dist(V, INT_MAX);  
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); 

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& edge : graph[u]) {
            int v = edge.dest;
            int weight = edge.weight;

    
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl;
    }
}

int main() {
    int V = 9;  
    vector<vector<Edge>> graph(V);

    graph[0].push_back({1, 4});
    graph[0].push_back({7, 8});
    graph[1].push_back({0, 4});
    graph[1].push_back({2, 8});
    graph[1].push_back({7, 11});
    graph[2].push_back({1, 8});
    graph[2].push_back({3, 7});
    graph[2].push_back({5, 4});
    graph[3].push_back({2, 7});
    graph[3].push_back({4, 9});
    graph[3].push_back({5, 14});
    graph[4].push_back({3, 9});
    graph[4].push_back({5, 10});
    graph[5].push_back({2, 4});
    graph[5].push_back({3, 14});
    graph[5].push_back({4, 10});
    graph[5].push_back({6, 2});
    graph[6].push_back({5, 2});
    graph[6].push_back({7, 1});
    graph[7].push_back({0, 8});
    graph[7].push_back({1, 11});
    graph[7].push_back({6, 1});
    graph[7].push_back({8, 7});
    graph[8].push_back({7, 7});
    graph[8].push_back({6, 6});

    int start = 0; 

     auto start_time = high_resolution_clock::now();
    dijkstra(V, graph, start);

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}
