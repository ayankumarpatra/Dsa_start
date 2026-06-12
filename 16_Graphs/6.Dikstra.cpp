#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int n = 5; // total number of nodes in the graph

// adj[u][v] stores the weight of edge from u to v
// if adj[u][v] = 0, there's no direct edge
int adj[n][n] = {
    {0, 4, 2, 0, 0},  // A(0): connects to B(weight 4), C(weight 2)
    {0, 0, 0, 5, 3},  // B(1): connects to D(weight 5), E(weight 3)
    {0, 1, 0, 8, 0},  // C(2): connects to B(weight 1), D(weight 8)
    {0, 0, 0, 0, 0},  // D(3): no outgoing edges
    {0, 0, 0, 0, 0}   // E(4): no outgoing edges
};

// void dijkstra(int src)
//   src = the starting node (e.g. pass 0 for node A)
void dijkstra(int src) {

    // dist[i] = best known shortest distance from src to node i
    // Start with all distances as "infinity" (unknown)
    vector<int> dist(n, INT_MAX);

    // visited[i] = true means we've finalized the shortest path to node i
    vector<bool> visited(n, false);

    // Distance from source to itself is always 0
    dist[src] = 0;

    // We need to process (n-1) nodes after the source
    for (int count = 0; count < n - 1; count++) {

        // --- STEP 1: Find the unvisited node with smallest distance ---
        int min = INT_MAX, u;

        for (int v = 0; v < n; v++) {
            // pick v only if not yet visited AND its distance is smaller
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;  // u = the "nearest unvisited" node
            }
        }

        // STEP 2: Mark this node as visited (finalized)
        visited[u] = true;

        // STEP 3: Update distances of u's neighbors
        for (int v = 0; v < n; v++) {
            // Update dist[v] only if ALL of these are true:
            //   - v is not yet visited
            //   - there IS an edge from u to v (adj[u][v] != 0)
            //   - u itself was reachable (dist[u] != INT_MAX)
            //   - going through u gives a shorter path to v
            if (!visited[v]
                && adj[u][v]              // edge u→v exists
                && dist[u] != INT_MAX     // u is reachable
                && dist[u] + adj[u][v] < dist[v]) {

                dist[v] = dist[u] + adj[u][v]; // RELAX the edge
            }
        }
    }

    // --- Print Results ---
    cout << "Distances from source node " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "  vertex " << i << " -> dist = " << dist[i] << "\n";
    }
}

int main() {
    dijkstra(0); // start from node A (index 0)
    return 0;
}