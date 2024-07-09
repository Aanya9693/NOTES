#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Initialize adjacency list
        vector<pair<int, int>> adj[n+1];
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        // Priority queue for Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, 1e9), parent(n+1);
        
        // Initialize the parent array
        for (int i = 1; i <= n; i++) parent[i] = i;
        
        // Distance from source to source is zero
        dist[1] = 0;
        pq.push({0, 1});
        
        // Dijkstra's algorithm
        while (!pq.empty()) {
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;
                // If a shorter path to adjNode is found
                if (dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        // If there is no path to the destination node
        if (dist[n] == 1e9) return {-1};
        
        // Construct the path
        vector<int> path;
        int node = n;
        
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        
        return path;
    }
};

int main() {
    // Sample input
    int n = 5, m = 6;
    vector<vector<int>> edges = {
        {1, 2, 2},
        {2, 5, 5},
        {2, 3, 4},
        {1, 4, 1},
        {4, 3, 3},
        {3, 5, 1}
    };

    Solution sol;
    vector<int> path = sol.shortestPath(n, m, edges);

    // Print the shortest path
    if (path.size() == 1 && path[0] == -1) {
        cout << "No path found" << endl;
    } else {
        cout << "Shortest path: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
