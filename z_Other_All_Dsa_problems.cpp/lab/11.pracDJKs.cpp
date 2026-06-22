#include<iostream>
#include<climits>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

const int n = 5; // total number of nodes in the graph

// adj[u][v] stores the weight of edge from u to v
// if adj[u][v] = 0, there's no direct edge
int adj[n][n] = {
//   a  b  c  d  e
    {0, 4, 2, 0, 0},  // A(0): connects to B(weight 4), C(weight 2)
    {0, 0, 0, 5, 3},  // B(1): connects to D(weight 5), E(weight 3)
    {0, 1, 0, 8, 0},  // C(2): connects to B(weight 1), D(weight 8)
    {0, 0, 0, 0, 0},  // D(3): no outgoing edges
    {0, 0, 0, 0, 0}   // E(4): no outgoing edges
};


void Dijkstra(int src){


}


int main (){

    Dijkstra(0);
    
    return 0;
}