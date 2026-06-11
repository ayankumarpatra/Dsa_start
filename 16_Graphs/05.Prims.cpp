#include<iostream>
#include<climits>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

const int n= 4; // Define the number of vertices


int adj[n][n] = {  // Hardcoded Adjacency Matrix
    {0, 2, 0, 6},
    {2, 0, 3, 8},
    {0, 3, 0, 0},
    {6, 8, 0, 0}
};


void primsmst(){

    vector<int> parent(n);
    vector<int> key(n,INT_MAX);
    vector<bool> mstset(n,false);

    key[0]=0;
    parent[0]=-1;

    for (int count=0;count<n-1;count++){
        int u;
        int min=INT_MAX;

        for (int v=0;v<n;v++){
            if (!mstset[v] && key[v]<min){
                min=key[v];
                u=v;
            }
        }
        
        mstset[u]=true;
        
        for (int v=0;v<n;v++){
            if (adj[u][v] && 
                !mstset[v] &&
                adj[u][v]<key[v] ){
                    parent[v]=u;
                    key[v]=adj[u][v];
                }
        }

    }

    cout<<"Prims Result \nEdge \t Weight \n";

    for (int i=1;i<n;i++){
        cout<<parent[i]<<" - "<<i <<" \t "<< adj[i][parent[i]]<<endl;
    }

}

int main (){

    primsmst();
    
    return 0;
}