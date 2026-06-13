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

    vector<int> dist (n,INT_MAX);
    dist[0]=0;// distance from source to source is always 0

    vector<bool> visited (n,false);

    for (int count =0;count<n-1;count++){
        // as n nodes and src already processed so remaningn n-1

        int min=INT_MAX;
        int u=-1;

        for (int v=0;v<n;v++){
            if (!visited[v] && dist[v]<=min){
                min=dist[v];
                u=v;
            }
        }
        // now u is the lowest cost neighbour
        visited[u]=true;
        for (int v=0;v<n;v++){
            if (
                !visited[v] && adj[u][v]!=0 // not connected by edge
                && dist[u]!=INT_MAX 
                && dist[u] + adj[u][v] <dist[v]
            ){
                dist[v]= dist[u] + adj[u][v];
            }
        }

    }

    // now all work done only printing remaning

    cout<<"Distance from Source "<<src<<" to \n";
    for (int v=0;v<n;v++){
        cout<<"vertex "<<v <<" is : "<<dist[v]<<endl;
    }
}


int main (){

    Dijkstra(0);
    
    return 0;
}