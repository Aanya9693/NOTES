#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex s using Dijkstra's algorithm.
    vector<int> dijkstra(int v, vector<vector<int>> adj[], int s) {
        // Priority queue to act as a min-heap
        // Stores pairs of (distance, vertex)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Distance array to store the shortest distance from the source to each vertex
        vector<int> dist(v, INT_MAX);
        
        // Distance from the source to itself is always zero
        dist[s] = 0;

        // Push the source vertex into the priority queue
        pq.push({0, s});
        
        while (!pq.empty()) {
            // Get the vertex with the smallest distance
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Iterate over all adjacent vertices of the current vertex
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWeight = it[1];

                // If a shorter path to adjNode is found
                if (dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

// Function to read input and execute the solution
int main() {
    int t;
    cin >> t;

    while (t--) {
        int v, e, s;
        cin >> v >> e >> s;
        
        // Graph represented as an adjacency list
        // Each element adj[i] is a list of pairs (adjacent vertex, edge weight)
        vector<vector<int>> adj[v];

        for (int i = 0; i < e; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // Uncomment this line if the graph is undirected
        }

        Solution sol;
        vector<int> result = sol.dijkstra(v, adj, s);

        for (int i = 0; i < v; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
