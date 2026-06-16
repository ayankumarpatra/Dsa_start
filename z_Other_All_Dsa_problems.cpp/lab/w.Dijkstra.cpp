#include<iostream>
#include<climits>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

const int n = 5; // total number of nodes in the graph

const int inf=INT_MAX;

// adj[u][v] stores the weight of edge from u to v
// if adj[u][v] = 0, there's no direct edge
int adj[n][n] = {
    {0, 4, 2, 0, 0},  // A(0): connects to B(weight 4), C(weight 2)
    {0, 0, 0, 5, 3},  // B(1): connects to D(weight 5), E(weight 3)
    {0, 1, 0, 8, 0},  // C(2): connects to B(weight 1), D(weight 8)
    {0, 0, 0, 0, 0},  // D(3): no outgoing edges
    {0, 0, 0, 0, 0}   // E(4): no outgoing edges
};


void dijkstra (int src){

    vector<int> dist(n,inf);
    dist[src]=0;

    vector<bool> visited(n,false);

    for (int count=0;count<n;count++){
        // total n nodes , src processed so remaining n-1

        int min=inf;
        int u=-1;

        for (int v=0; v<n ;v++){
            if (
                !visited[v]// v not visited
                && dist[v]<=min// dist to v is less than min
            ){
                u=v;
                min=dist[v];
            }
        }
        // now u is lowest cost neighbour

        visited[u]=true;

        for (int v=0 ;v<n ;v++ ){// this time neutralizing edges 
            if (
                dist[u]!=inf// u is reaachable
                && adj[u][v]!=0 // edge exist btn u and v
                && dist[u]+adj[u][v]<dist[v] // cost from src->v via u is less than src->v precalculated 
            ){
                dist[v]=dist[u]+adj[u][v];
            }
        }
    }

    // everything done , printing remaining 

    cout<<"Distance from vertex "<<src<<" to \n";

    for (int v=0; v<n ;v++){
        cout<<"Vertex "<<v<<" is : "<<dist[v]<<endl;
    }
}


int main (){

    dijkstra(0);
    
    return 0;
}