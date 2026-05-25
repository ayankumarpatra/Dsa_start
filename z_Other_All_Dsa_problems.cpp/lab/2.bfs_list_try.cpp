#include<iostream>
#include<queue>
#include<vector>

using namespace std ;

const int n=10;

vector<vector<int>> adj={
    {},
    {2,6},//1
    {1,3,4},//2
    {2},//3
    {2,5},//4
    {4,8},//5
    {1,9,7},//6
    {6,8},//7
    {7,5},//8
    {6},//9
};

void bfs(int node){
    vector<bool> visited(n,false);

    queue<int> q;

    q.push(node);

    while (!q.empty())
    {
        int currnode=q.front();
        q.pop();
        cout<<currnode<<" ";
        visited[currnode]=true;
        
        for (int em:adj[currnode]){
            if (!visited[em]){
                q.push(em);
                visited[em]=true;
            }
        }

    }
}

int main (){

    bfs(1);
    
    return 0;
}