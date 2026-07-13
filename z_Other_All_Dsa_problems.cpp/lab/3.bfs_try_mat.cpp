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

void bfs(int start){

vector<bool> visited (n,false);
queue<int> q;

q.push(start);
visited[start]=true;

while (q.size()>0)
{
    int currnode=q.front();
    cout<<currnode<<" ";
    q.pop();

    for (int i=0;i<n;i++){
        if (adj[currnode][i]==1 && !visited[i]){
            visited[i]=true;
            q.push(i);
        }
    }
}


}

int main (){

    bfs(0);
    
    return 0;
}