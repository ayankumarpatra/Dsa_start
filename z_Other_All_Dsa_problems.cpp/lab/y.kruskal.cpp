#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

const int n = 5; // total number of nodes

struct edge{
    int src,dest,weight;
};

bool comparator(edge a , edge b){
    return a.weight < b.weight;
}
int parent[n];

int find (int v){ // find parent node of a node
    if (parent[v]!=v){
        parent[v]=find(parent[v]);
    }
    return parent[v];
}

void unite (int x , int y){
    int rootx=parent[x];
    int rooty=parent[y];

    parent[rootx]=rooty;
}


void kruskalmst(edge edges[] , int numedges){

    // sorting edges 
    sort(edges,edges+numedges,comparator);

    //filling the parent 

    for (int i=0;i<n;i++){
        parent[i]=i;
    }

    vector<edge> mst;

    // iterating through each edge

    for (int e=0;e<numedges;e++){

        int u=edges[e].src;
        int v=edges[e].dest;
        int w=edges[e].weight;

        int rootu=find(u);
        int rootv=find(v);

        if (rootu!=rootv){ // safe to merge not from a common parent so no cycle 
            mst.push_back(edges[e]);
            unite(rootu,rootv);// merge the group
        }

        if ((int)mst.size()==n-1){
            break;
        }
    }

    // done only print remaining 
    int totalweight=0;

    cout<<"Kruskals mst result\n";
    cout<<"Edge \t Weight\n";

    for (auto e : mst){
        cout<<e.src<<" - "<<e.dest<<" \t "<<e.weight<<endl;
        totalweight+=e.weight;
    }

    cout<<"\nTotalweight : "<<totalweight;
}

int main() {
    // Same graph as the visual above
    // Nodes: A=0, B=1, C=2, D=3, E=4
    edge edges[] = {
        {0, 1, 2},  // A-B weight 2
        {0, 2, 3},  // A-C weight 3
        {1, 2, 6},  // B-C weight 6
        {1, 3, 5},  // B-D weight 5
        {1, 4, 4},  // B-E weight 4
        {2, 4, 7},  // C-E weight 7
        {3, 4, 1}   // D-E weight 1
    };

    int numedgess = 7;

    kruskalmst(edges, numedgess);
    return 0;
}