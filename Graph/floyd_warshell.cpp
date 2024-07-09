#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void shortest_distance(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Initialize the matrix for Floyd-Warshall algorithm
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If no edge exists between nodes i and j
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 1e9; // Use a large value to represent infinity
                }
                // Distance to self is zero
                if (i == j) matrix[i][j] = 0;
            }
        }

        // Floyd-Warshall algorithm to find the shortest paths
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Update the shortest path from i to j through k
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        // Convert unreachable nodes back to -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1e9) {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the adjacency matrix (use -1 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution sol;
    sol.shortest_distance(matrix);

    cout << "The shortest distance matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*

2
0 25
-1 0
*/