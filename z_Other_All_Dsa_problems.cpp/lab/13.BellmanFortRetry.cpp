#include<iostream>
#include<climits>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

const int n=5;// no of vertices 

struct edge {// each edge with source , dest and weight 
    int src,dest,weight;
};


void bellmanford (edge edges[], int numedges, int src){
    // edgelist , number of edges , source edge to start 

    vector<int> dist (n,INT_MAX);
    dist[src]=0;

    for (int count=0;count<n-1;count++){

        for (int e=0;e<numedges;e++){
            int u=edges[e].src;
            int v=edges[e].dest;
            int w=edges[e].weight;

            if (
                dist[u]!=INT_MAX// u is reachable
                && dist[u]+w<dist[v]// src -> u -> v is less than old calculated src->v
            ){
                dist[v]=dist[u]+w;
            }
        }
    }

    // now have to check once more if still an edge can be relaxed means its a -ve edge so no shortest path
        for (int e=0;e<numedges;e++){
            int u=edges[e].src;
            int v=edges[e].dest;
            int w=edges[e].weight;

            if (
                dist[u]!=INT_MAX// u is reachable
                && dist[u]+w<dist[v]// src -> u -> v is less than old calculated src->v
            ){
                cout<<"Negetive weight cycle detected \n cant find any shortest path \n";
                return;// terminating the prog 
            }
        }  
    
    // now all checked only print 

    cout<<" Distance from source "<<src<<" to \n";

    for (int v=0;v<n;v++){
        cout<<"Vertex "<<v<<" is "<< dist[v]<<endl;
    }
}



int main (){

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

    bellmanford(edges, numEdges, 0); // start from A (index 0)
    return 0;
    
}