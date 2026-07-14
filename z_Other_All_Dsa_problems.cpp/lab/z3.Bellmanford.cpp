#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int n = 5; // total number of vertices

struct Edge {
    int src,dest,weight;
};

void bellmanFord(Edge edges[], int numEdges, int src) {

    vector<int> dist(n,INT_MAX);
    dist[src]=0;

    for (int count=0; count<n-1; count++){

        for (int e=0;e<numEdges;e++ ){
            int u=edges[e].src;
            int v=edges[e].dest;
            int w=edges[e].weight;

            if (
                dist[u]!=INT_MAX // u is reachable
                && dist[u]+w<dist[v]
            ){
                dist[v]=dist[u]+w;
            }
        }
    }

    // -ve cycle dtection

        for (int e=0;e<numEdges;e++ ){
            int u=edges[e].src;
            int v=edges[e].dest;
            int w=edges[e].weight;

            if (
                dist[u]!=INT_MAX // u is reachable
                && dist[u]+w<dist[v]
            ){
                cout<<"-ve cycle detected Exitting \n ";
                return;
            }
        }

    // all safe only printing remaining 

    cout<<"Distance from source to vertex \n ";
    for (int v=0;v<n;v++){
        cout<<v<<" "<<dist[v]<<endl;
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