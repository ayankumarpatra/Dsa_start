#include <iostream>
#include <vector>

using namespace std;

const int inf = 1e8;

// Look how clean the parameters are! No fixed columns [n] needed anymore.


void floydWarshall(vector<vector<int>> graph){

    int n=graph.size();
    // copying the whole graph arr in dist 
    vector<vector<int>> dist=graph;

    for (int v=0;v<n;v++ ){

        // now will check every pair of nodes (i,j)

        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){

                // if either i or j is unreachable , skip

                if (dist[i][v]==inf || dist[v][j]==inf){
                    continue;
                }

                // else check if dist is less or not

                if (dist[i][v]+ dist[v][j]< dist[i][j]){
                    dist[i][j]=dist[i][v]+ dist[v][j];
                }
            }
        }

    }

    // after this have to check for a -ve cycle

    for (int i=0;i<n;i++){
        if (dist[i][i]<0){
            cout<<"-ve cycle detected \n";
            return;
        }
    }
    
    // done all now printing the matrix only 
    
    cout<<"Min dist Matrix is \n\t";
    for (int i=0;i<n;i++){
            cout<<i<<"\t";
    }
    cout<<endl;

    for (int i=0;i<n;i++){
        cout<<i<<"\t";
        for (int j=0;j<n;j++){
            cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }

}

int main() {

    // Declaring a 2D vector is very easy:
    vector<vector<int>> adj = {
        {  0,   3,   8, inf},
        {inf,   0, inf,   7},
        {inf,   2,   0, inf},
        { -4, inf,   1,   0}
    };

    floydWarshall(adj);

    return 0;
}