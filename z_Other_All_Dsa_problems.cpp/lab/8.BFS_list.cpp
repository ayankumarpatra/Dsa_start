#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

const int n=6;

vector<vector<int>> adj = {
    {1, 2},    // node 0 connects to 1, 2
    {0, 3, 4}, // node 1 connects to 0, 3, 4
    {0, 5},    // node 2 connects to 0, 5
    {1},       // node 3 connects to 1
    {1},       // node 4 connects to 1
    {2}        // node 5 connects to 2
};

void bfs (int start){

    vector<bool> visited(n,false);

    queue<int> q;

    visited[start]=true;

    q.push(start);

    while (q.size()>0)
    {
        auto node=q.front();
        q.pop();
        cout<<node<<" ";

        for (auto currnode:adj[node]) {
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