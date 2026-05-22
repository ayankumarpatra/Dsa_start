#include<iostream>
#include<queue>
#include<vector>

using namespace std ;

// adjacency list 

const int n=6;// nodes 0 to 5 

vector<vector<int>> adj={
    {1,2},
    {0,3,4},
    {0,5},
    {1},
    {1},
    {2}
};


void bfs(int start){
    vector<bool> visited(n,false);

    queue<int> q;

    q.push(start);
    visited[start]=true;

    while (!q.empty())
    {
        int node=q.front();
        cout<<node<<" ";
        q.pop();

        for (int currnode:adj[node]){
            if (!visited[currnode]){
                visited[currnode]=true;
                q.push(currnode);
            }
        }
    }
    
}


int main (){

    bfs(0);
    
    return 0;
}