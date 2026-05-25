#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

const int n=10;

vector<vector<int>> adj={
   //0 1 2 3 4 5 6 7 8 9
    {0,0,0,0,0,0,0,0,0,0},//0
    {0,0,1,0,0,0,1,0,0,0},//1
    {0,1,0,1,1,0,0,0,0,0},//2
    {0,0,1,0,0,0,0,0,0,0},//3
    {0,0,1,0,0,1,0,0,0,0},//4
    {0,0,0,0,1,0,0,0,1,0},//5
    {0,1,0,0,0,0,0,1,0,1},//6
    {0,0,0,0,0,0,1,0,1,0},//7
    {0,0,0,0,0,1,0,1,0,0},//8
    {0,0,0,0,0,0,1,0,0,0},//9
};


vector<bool> visited(n,false);

void dfs(int node){
    cout<<node<<" ";
    visited[node]=true;

    for (int currnode=0;currnode<n;currnode++ ){
        if (!visited[currnode] && adj[node][currnode]==1){
            dfs(currnode);
        }
    }
}


int main (){

    dfs(1);
    
    return 0;
}