#include<iostream>
#include<stack>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std ;


const int n = 5;

struct edge{
    int src,dest,weight;
};

void bellmanFord(edge edges[], int numEdges, int src) {
    
// failed 3 rd time 

}

int main (){


    // Same graph as the visual above
    // Nodes: A=0, B=1, C=2, D=3, E=4
    edge edges[] = {
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