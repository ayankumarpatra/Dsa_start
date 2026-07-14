#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int n = 5; // total number of nodes

// adj[u][v] = weight of undirected edge between u and v
// 0 means no edge
int adj[n][n] = {
    {0, 2, 3, 0, 0},  // A(0): A-B=2, A-C=3
    {2, 0, 6, 5, 4},  // B(1): B-A=2, B-C=6, B-D=5, B-E=4
    {3, 6, 0, 0, 7},  // C(2): C-A=3, C-B=6, C-E=7
    {0, 5, 0, 0, 1},  // D(3): D-B=5, D-E=1
    {0, 4, 7, 1, 0}   // E(4): E-B=4, E-C=7, E-D=1
};

// -------------------------------------------------------
// void primMST()
//   No parameter needed — we always start from node 0
// -------------------------------------------------------
void primMST() {

    // parent[v] = which node connected v into the MST
    // This lets us print the actual MST edges at the end
    vector<int> parent(n);

    // dist[v] = cheapest edge weight to pull v into the MST
    // Start with all as "infinity" (unknown); simple words its the dist 
    vector<int> dist(n, INT_MAX);

    // visited[v] = true means v is already inside the MST
    vector<bool> visited(n, false);

    // Start from node 0
    // dist[0] = 0 means "it costs nothing to start here"
    dist[0] = 0;

    // parent[0] = -1 means "node 0 has no parent, it's the root"
    parent[0] = -1;

    // We need to add (n-1) more nodes to complete the MST
    for (int count = 0; count < n - 1; count++) {

        // --- STEP 1: Find the node NOT in MST with smallest dist ---
        int min = INT_MAX, u;

        for (int v = 0; v < n; v++) {
            // pick v only if not yet in MST AND its dist is smaller
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v; // u = cheapest node to pull in next
            }
        }

        // --- STEP 2: Add u to the MST ---
        visited[u] = true;

        // --- STEP 3: Update dists of u's neighbors ---
        for (int v = 0; v < n; v++) {
            // Update dist[v] only if ALL of these are true:
            //   - there IS an edge from u to v (adj[u][v] != 0)
            //   - v is NOT yet in the MST
            //   - the edge u-v is cheaper than v's current dist
            if (adj[u][v]           // edge u-v exists
                && !visited[v]       // v not yet in MST
                && adj[u][v] < dist[v]) // cheaper than what we knew
                
                { 
                parent[v] = u;          // record: v was reached via u
                dist[v] = adj[u][v];     // update dist to this cheaper edge
            }
        }
    }

    // --- Print the MST edges and their weights ---
    cout << "Prim's MST result:\n";
    cout << "Edge \t Weight\n";
    for (int i = 1; i < n; i++) { // start from 1, node 0 has no parent
        cout << parent[i] << " - " << i << "\t" << adj[i][parent[i]] << "\n";
    }
}

int main() {
    primMST();
    return 0;
}