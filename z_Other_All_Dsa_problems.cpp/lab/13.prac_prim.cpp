#include<iostream>
#include<stack>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std ;

const int n = 5; // total number of nodes in the graph

// adj[u][v] stores the weight of edge from u to v
// if adj[u][v] = 0, there's no direct edge
int adj[n][n] = {
    {0, 2, 3, 0, 0},  // A(0): A-B=2, A-C=3
    {2, 0, 6, 5, 4},  // B(1): B-A=2, B-C=6, B-D=5, B-E=4
    {3, 6, 0, 0, 7},  // C(2): C-A=3, C-B=6, C-E=7
    {0, 5, 0, 0, 1},  // D(3): D-B=5, D-E=1
    {0, 4, 7, 1, 0}   // E(4): E-B=4, E-C=7, E-D=1
};

void prims (){// no argument will take 

    vector<int> parent(n);
    parent[0]=-1;// first node , root have no parents 

    vector<int> key (n,INT_MAX); // key is similar to dist 
    key [0]=0; // sim self to self dist is 0

    vector<bool> mstset(n,false); // if the node already taken in mstset or not

    for (int count=0;count<n-1;count++){
        int min=INT_MAX;
        int u;

        for (int v=0;v<n;v++){// getting u , same as dijkstra 
            if (
                !mstset[v] // v not visited
                && key[v]<=min // dist is eq to min 
            ){
                u=v;
                min=key[v];
            }
        }
        // now u is the min cost neighbour

        mstset[u]=true;// similar to visited [u]=true in dijkstra

        // neutralizing the edges 

        for (int v=0;v<n ;v++){
            if (
                !mstset[v]// v not visited 
                && adj[u][v]!=0 // edge exist 
                // from here the change start from dijkstra 
                && adj[u][v]<key[v]
            ){
                parent[v]=u;
                key[v]=adj[u][v];
            }
        }
    }

    // now remaning print only 

    cout<<"Edge   \t Cost \n";
    for (int v=1;v<n;v++ ){// obv from 1 as 0 no parent 
        cout<<parent[v]<<" -> "<<v<<"\t"<<adj[v][parent[v]]<<endl;
    }

}


int main (){

    prims();

    return 0;
}