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

    vector<bool> visited(n,false);

    vector<int> parent (n);
    parent[0]=-1;
    vector<int> dist(n,INT_MAX);
    dist[0]=0;


    for (int count=0;count<n-1;count++){

        int min=INT_MAX,u;

        for (int v=0;v<n;v++){
            if (!visited[v]
            && dist[v]<min
            ){
                min=dist[v];
                u=v;
            }
        }

        // now us the lowest val neighbour 

        visited[u]=true;

        for (int v=0;v<n;v++){
            // have to check if src -> u -> v
            if (
                !visited[v]
                && adj[u][v]!=0 // edge exist u to v
                && dist[v]>adj[u][v]
            ){
                parent[v]=u;
                dist[v]=adj[u][v];
            } 
        }
    }

    // now only printign remaining 

    cout<<"Edge \t Weight\n";
    for (int v=0;v<n;v++){
        cout<<parent[v]<<" -> "<<v<<" : "<<dist[v]<<endl;
    }
}

int main() {
    primMST();
    return 0;
}