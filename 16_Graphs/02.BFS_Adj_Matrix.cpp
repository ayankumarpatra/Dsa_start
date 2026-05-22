#include<iostream>
#include<queue>
#include<vector>

using namespace std ;

// the adj matrix 

const int n=6;// means node 0 to 5 

vector<vector<int>> adj {
    //0 1 2 3 4 5
    {0,1,1,0,0,0},
    {1,0,0,1,1,0},
    {1,0,0,0,0,1},
    {0, 1, 0, 0, 0, 0},  // node 3
    {0, 1, 0, 0, 0, 0},  // node 4
    {0, 0, 1, 0, 0, 0}   // node 5
};

void bfs (int start){

    vector<bool> visited(n,false);
    queue<int> q;

    visited[start]=true;
    q.push(start);

    while (!q.empty())
    {
        int node=q.front();
        q.pop();

        cout<<node<<" ";

        for(int currnode=0;currnode<n;currnode++){
            if (adj[node][currnode]==1 && !visited[currnode]){
                q.push(currnode);
                visited[currnode]=true;
            }
        }
    }
    

}


int main (){

    bfs(0);
    return 0;
}  