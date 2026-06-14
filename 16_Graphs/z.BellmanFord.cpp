#include<iostream>
#include<climits>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

const int n=5;

struct edge {
    int src,dest,weight;
};// edges source dest , weight 

void bellmanford(edge edges [] ,int src, int edgecount){

    vector<int> dist (n,INT_MAX);
    dist[src]=0;

    for (int count=0;count<n-1;count++){

        // check min edge 
        for (int e=0;e<edgecount;e++){
            int u =edges[e].src;
            int v =edges[e].dest;
            int w =edges[e].weight;

                if ( dist[u]!=INT_MAX // u is reachable
                    && dist[u]+w <= dist[v] // u to v via w , less than pre calculated src to v
                ){
                    dist[v]= dist[u]+w;
                }
        }
    }
        // check once again if still value be small means -ve edge exist 
            for (int e=0;e<edgecount;e++){
            int u =edges[e].src;
            int v =edges[e].dest;
            int w =edges[e].weight;

                if ( dist[u]!=INT_MAX // u is reachable
                    && dist[u]+w < dist[v] // u to v via w , less than pre calculated src to v
                ){
                    cout<<"- ve edge detected \n";
                    return;
                } 
    // now everything pass , only print remain 
    }

    cout<<"Distance from source vertex "<<src<<" to \n";

    for (int v=0;v<n;v++){
        cout<<"Vertex "<<v<<" is "<<dist[v]<<endl;
    }

}


int main (){

    edge edges []= {
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

    bellmanford(edges, 0,numEdges); // start from A (index 0)

    return 0;
}