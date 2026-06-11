#include<iostream>
#include<climits>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


const int n= 4; // Define the number of vertices


int adj[n][n] = {  // Hardcoded Adjacency Matrix
    {0, 2, 0, 6},
    {2, 0, 3, 8},
    {0, 3, 0, 0},
    {6, 8, 0, 0}
};



void primsmst(){

    vector<int> parent (n);
    vector<int> key (n,INT_MAX);
    vector<bool> mastset (n,false);

}



int main (){

    
    return 0;
}