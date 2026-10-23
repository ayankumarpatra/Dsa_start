#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

/*

Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

In one shift operation:

    Element at grid[i][j] moves to grid[i][j + 1].
    Element at grid[i][n - 1] moves to grid[i + 1][0].
    Element at grid[m - 1][n - 1] moves to grid[0][0].


*/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        // moving out all the elements in a deque 

        deque<int> dq;

        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                dq.push_back(grid[i][j]);
            }
        }

        while (k>0){
            dq.push_front(dq.back());
            dq.pop_back();
            k--;
        }


        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                    grid[i][j]=dq.front();
                    dq.pop_front();
            }
        }


    }
};


int main (){

    
    return 0;
}