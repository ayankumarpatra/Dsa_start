#include<iostream>
#include<stack>
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

vector<bool> visited (n,false);

void dfs (int node){
    cout<<node<<" ";
    visited[node]=true;
    for (int currnode: adj[node]){
        if (!visited[currnode]){
            dfs(currnode);
        }
    }
}

int main (){

    dfs(1);

    return 0;
}