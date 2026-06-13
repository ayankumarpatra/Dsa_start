#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int n = 5; // total number of vertices

// We store the graph as an edge list (not adj matrix)
// because Bellman-Ford loops over ALL edges — a list is natural
// Each edge: {src, dest, weight}
struct Edge {
    int src, dest, weight;
};

// -------------------------------------------------------
// void bellmanFord(Edge edges[], int numEdges, int src)
//   edges[]   = the full list of all edges in the graph
//   numEdges  = how many edges total
//   src       = the starting node
// -------------------------------------------------------
void bellmanFord(Edge edges[], int numEdges, int src) {

    // dist[i] = best known shortest distance from src to node i
    // Initialize all as "infinity" (unknown)
    vector<int> dist(n, INT_MAX);

    // Distance from source to itself is 0
    dist[src] = 0;

    // -------------------------------------------------------
    // MAIN LOOP: repeat (n-1) times
    // Why n-1? The longest shortest path in n nodes has at most
    // n-1 edges. So after n-1 rounds, we have found everything.
    // -------------------------------------------------------
    for (int count = 0; count < n - 1; count++) {

        // Go through every single edge in the graph
        for (int e = 0; e < numEdges; e++) {

            int u = edges[e].src;
            int v = edges[e].dest;
            int w = edges[e].weight;

            // RELAX the edge u→v
            // Only update if:
            //   - u is reachable (dist[u] != INT_MAX)
            //   - going through u gives a shorter path to v
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // -------------------------------------------------------
    // BONUS: Negative cycle detection
    // Do one MORE round. If any distance still reduces,
    // a negative weight cycle exists (shortest path = -infinity)
    // -------------------------------------------------------
    for (int e = 0; e < numEdges; e++) {
        int u = edges[e].src;
        int v = edges[e].dest;
        int w = edges[e].weight;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Negative weight cycle detected!\n";
            return; // can't give valid shortest paths
        }
    }

    // Print the final shortest distances
    cout << "Distances from source node " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "  vertex " << i << " -> dist = " << dist[i] << "\n";
    }
}

int main() {
    // Same graph as the visual above
    // Nodes: A=0, B=1, C=2, D=3, E=4
    Edge edges[] = {
        {0, 1,  6},  // A→B weight  6
        {0, 2,  7},  // A→C weight  7
        {1, 2,  8},  // B→C weight  8
        {1, 3, -4},  // B→D weight -4  (negative!)
        {1, 4,  5},  // B→E weight  5
        {2, 4, -3},  // C→E weight -3  (negative!)
        {3, 2,  9},  // D→C weight  9
        {4, 3,  7}   // E→D weight  7
    };

    int numEdges = 8; // total number of edges

    bellmanFord(edges, numEdges, 0); // start from A (index 0)
    return 0;
}