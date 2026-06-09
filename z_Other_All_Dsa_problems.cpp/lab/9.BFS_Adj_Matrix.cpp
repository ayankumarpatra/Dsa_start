#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

const int n=6;

int adcurrnode[n][n] = {
//   0  1  2  3  4  5
    {0, 1, 1, 0, 0, 0},  // node 0
    {1, 0, 0, 1, 1, 0},  // node 1
    {1, 0, 0, 0, 0, 1},  // node 2
    {0, 1, 0, 0, 0, 0},  // node 3
    {0, 1, 0, 0, 0, 0},  // node 4
    {0, 0, 1, 0, 0, 0}   // node 5
};


void bfs(int start){
    vector <bool> visited (n,false);

    queue<int> q;
    q.push(start);
    visited[start]=true;

    for (int i=0;i<n;i++){
        auto node=q.front();
        q.pop();
        cout<<node<<" ";
        for (int currnode=0;currnode<n;currnode++){
            if (adcurrnode[i][currnode]==1 && !visited[currnode]){
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