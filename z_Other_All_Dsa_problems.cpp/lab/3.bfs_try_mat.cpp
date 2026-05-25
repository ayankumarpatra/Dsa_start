#include<iostream>
#include<queue>
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

void bfs(int node){

    queue<int> q;
    vector<bool> visited (n,false);
    q.push(node);

    while (!q.empty())
    {
        int frontnode=q.front();
        q.pop();

        cout<<frontnode<<" ";
        visited[frontnode]=true;

        for (int i=0;i<n;i++){
            if (!visited[i] && adj[frontnode][i]==1){
                q.push(i);
                visited[i]=true;
            }
        }
    }
    

}

int main (){

    
    return 0;
}