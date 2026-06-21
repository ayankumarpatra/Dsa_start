#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

const int n = 5; // total number of nodes

struct edge{
    int src,dest,weight;
};

bool comparator(edge a , edge b){
    return a.weight>b.weight;
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