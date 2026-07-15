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

// Failed 6 th time 
}

int main() {
    primMST();
    return 0;
}