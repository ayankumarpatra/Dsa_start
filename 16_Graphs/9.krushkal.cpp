#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

const int n = 5; // total number of nodes

// Just like Bellman-Ford, we store edges in an edge list
// Each edge: {src, dest, weight}
struct edge {
    int src, dest, weight;
};

// Comparator function for sorting
bool comparator(edge a, edge b) {
    return a.weight < b.weight;
}

// -------------------------------------------------------
// UNION-FIND helper — tracks which group each node is in
// parent[i] = who is the "leader/root" of node i's group
// -------------------------------------------------------
int parent[n];

// find(x): follow the chain up to find the root of x's group
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]); // path compression (shortcut)
    return parent[x];
}

// unite(x, y): merge the groups of x and y into one
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    parent[rootX] = rootY; // make one root point to the other
}

// -------------------------------------------------------
// void kruskalMST(edge edges[], int numEdges)
//   edges[]   = all edges in the graph
//   numEdges  = total number of edges
// -------------------------------------------------------
void kruskalMST(edge edges[], int numEdges) {

    // STEP 1: Sort all edges by weight (smallest first)
    sort(edges, edges + numEdges, comparator);

    // STEP 2: Initialize Union-Find
    // Every node starts as its own group — parent[i] = i
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // To collect MST result edges for printing
    vector<edge> mst;

    // STEP 3: Go through sorted edges one by one
    for (int i = 0; i < numEdges; i++) {

        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;

        // Check if u and v are in different groups
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            // Different groups → safe to add (no cycle)
            mst.push_back(edges[i]);
            unite(u, v); // merge their groups
        }
        // Same group → skip (would create a cycle)

        // Stop early once we have exactly n-1 edges
        if ((int)mst.size() == n - 1) break;
    }

    // Print MST edges and total weight
    int totalWeight = 0;
    cout << "Kruskal's MST result:\n";
    cout << "Edge \t Weight\n";
    for (edge e : mst) {
        cout << e.src << " - " << e.dest << "\t" << e.weight << "\n";
        totalWeight += e.weight;
    }
    cout << "Total MST weight: " << totalWeight << "\n";
}

int main() {
    // Same graph as the visual above
    // Nodes: A=0, B=1, C=2, D=3, E=4
    edge edges[] = {
        {0, 1, 2},  // A-B weight 2
        {0, 2, 3},  // A-C weight 3
        {1, 2, 6},  // B-C weight 6
        {1, 3, 5},  // B-D weight 5
        {1, 4, 4},  // B-E weight 4
        {2, 4, 7},  // C-E weight 7
        {3, 4, 1}   // D-E weight 1
    };

    int numEdges = 7;

    kruskalMST(edges, numEdges);
    return 0;
}