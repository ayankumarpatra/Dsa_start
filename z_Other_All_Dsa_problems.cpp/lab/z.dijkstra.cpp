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
    {0, 4, 2, 0, 0},  // A(0): connects to B(weight 4), C(weight 2)
    {0, 0, 0, 5, 3},  // B(1): connects to D(weight 5), E(weight 3)
    {0, 1, 0, 8, 0},  // C(2): connects to B(weight 1), D(weight 8)
    {0, 0, 0, 0, 0},  // D(3): no outgoing edges
    {0, 0, 0, 0, 0}   // E(4): no outgoing edges
};

void dijkstra (int src){
    vector<int> dist (n,INT_MAX);
    dist[src]=0;

    vector<bool> visited(n,false);

    for (int count=0;count<n-1;count++){

        int min=INT_MAX;
        int u=-1;

        for (int v=0;v<n;v++){
            if ( !visited[v] // not visited 
                && dist[v]<=min // dist is min than curr dist 

            ){

                min=dist[v];
                u=v;
            }
        }
        
        // now u is the lowest cost neighbour 
        
        visited[u]=true;
        
        for (int v=0;v<n;v++){
            if ( dist[u]!=INT_MAX // u is reachable 
                && adj[u][v]!=0 // u to v edge must be there
                && !visited[v] // v isnt visited 
                &&  dist[u]+adj[u][v]<=dist[v]

            ){
                dist[v]=dist[u]+adj[u][v];
            }
        }

    }

    // now only printing remaninng 

    cout<<" Distance from source "<<src<<" to \n";

    for (int v=0;v<n;v++){
        cout<<"Vertex "<<v<<" is "<<dist[v]<<endl;
    }

}


int main (){

    dijkstra(0);
    return 0;
}