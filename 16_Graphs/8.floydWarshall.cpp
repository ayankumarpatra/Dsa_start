#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e8;

// Look how clean the parameters are! No fixed columns [n] needed anymore.
void floydWarshall(const vector<vector<int>>& adj) {

    int n = adj.size(); // Dynamically gets the number of vertices

    vector<vector<int>> dist = adj;

    // -------------------------------------------------------
    // MAIN LOOP: try each node k as an intermediate node
    // Outer loop k = "which node are we routing through?"
    // -------------------------------------------------------
    for (int k = 0; k < n; k++) {

        // For every pair of nodes (i, j):
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // Skip if i or j are unreachable via k
                // (avoids overflow when adding INF + something)
                if (dist[i][k] == INF || dist[k][j] == INF)
                    continue;

                // THE CORE QUESTION:
                // Is going i → k → j shorter than the current i → j?
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j]; // update!
                }
            }
        }
    }

    // -------------------------------------------------------
    // Negative cycle detection:
    // After the algorithm, if dist[i][i] < 0 for any node i,
    // it means there's a negative cycle reachable from i
    // (a node's shortest path to itself went negative — impossible without a negative cycle)
    // -------------------------------------------------------
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative cycle detected!\n";
            return;
        }
    }

    // Print the final all-pairs distance matrix
    cout << "All-pairs shortest distances:\n";
    cout << "\t";
    for (int j = 0; j < n; j++)
        cout << j << "\t";
    cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << i << "\t";
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {

    // Declaring a 2D vector is very easy:
    vector<vector<int>> adj = {
        {  0,   3,   8, INF},
        {INF,   0, INF,   7},
        {INF,   2,   0, INF},
        { -4, INF,   1,   0}
    };

    floydWarshall(adj);

    return 0;
}