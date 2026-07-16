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

void bfs(int start){

    queue<int> q;
    vector<int> visited(n,false);
    q.push(start);

    while (!q.empty())
    {
        int node=q.front();
        q.pop();

        cout<<node<<" ";

        for (int currnode : adj[node]){
            if (!visited[currnode]){
                q.push(currnode);
                visited[currnode]=true;
            }
        }
    }
    
    
}

int main (){

    bfs(1);
    
    return 0;
}