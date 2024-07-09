#include <bits/stdc++.h>
using namespace std;

// Bellman-Ford algorithm to find the shortest path from a source vertex to all other vertices
vector<int> bellman_ford(int v, vector<vector<int>>& edges, int s) {
    // Initialize distance array with a large value (infinity)
    vector<int> dist(v, 1e8);
    // Set the distance to the source vertex as 0
    dist[s] = 0;
    
    // Relax all edges v-1 times
    for (int i = 0; i < v - 1; i++) {
        // Iterate through all edges
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            // If the current distance to u is not infinity and the new distance is shorter
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    
    // Check for negative weight cycles
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        // If we can still relax an edge, then there is a negative weight cycle
        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return { -1 }; // Return -1 to indicate a negative cycle
        }
    }
    
    return dist; // Return the shortest distances
}

int main() {
    int v, e, s;
    // cout << "Enter the number of vertices: ";
    cin >> v;
    // cout << "Enter the number of edges: ";
    cin >> e;
    
    vector<vector<int>> edges(e, vector<int>(3));
    // cout << "Enter the edges in the format (u v wt):\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    
    // cout << "Enter the source vertex: ";
    cin >> s;
    
    vector<int> result = bellman_ford(v, edges, s);
    
    if (result.size() == 1 && result[0] == -1) {
        cout << "Graph contains a negative weight cycle\n";
    } else {
        // cout << "Shortest distances from source vertex " << s << ":\n";
        for (int i = 0; i < v; i++) {
            if (result[i] == 1e8) {
                cout << "INF"<<" ";
            } else {
                cout <<result[i]<<" ";
            }
        }
    }
    cout<<endl;
    return 0;
}
