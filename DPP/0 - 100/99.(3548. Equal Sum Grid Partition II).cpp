#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        unordered_map<long long, int> allEl;
        vector<long long> row(n, 0);
        
        // 1. Calculate prefix sums and global element frequencies
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                row[i] += grid[i][j];
                allEl[(long long)grid[i][j]]++;
            }
            if(i > 0) row[i] += row[i-1];
        }
        
        long long colSum = 0, totSum = row[n-1];
        unordered_map<long long, int> partial;
        
        // 2. Evaluate all Horizontal Cuts
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < m; j++){
                partial[(long long)grid[i][j]]++;
            }
            long long topSum = row[i];
            long long bottomSum = totSum - topSum;
            
            if(topSum == bottomSum) return true;
            else if(topSum > bottomSum){
                long long diff = topSum - bottomSum;
                if(m == 1){
                    if(i > 0){
                        if(grid[0][0] == diff || grid[i][0] == diff) return true;
                    }
                } else {
                    if(i == 0){
                        if(grid[0][0] == diff || grid[0][m-1] == diff) return true;
                    } else {
                        if(partial.count(diff)) return true;
                    }
                }
            } else {
                long long diff = bottomSum - topSum;
                if(m == 1){
                    if(i < n-1){
                        if(grid[n-1][0] == diff || grid[i+1][0] == diff) return true;
                    }
                } else {
                    if(i == n-2){
                        if(grid[n-1][0] == diff || grid[n-1][m-1] == diff) return true;
                    } else {
                        int pCount = partial.count(diff) ? partial[diff] : 0;
                        if(allEl.count(diff) && (allEl[diff] - pCount) > 0) return true;
                    }
                }
            }
        } 
        
        // 3. Evaluate all Vertical Cuts
        partial.clear();
        for(int j = 0; j < m-1; j++){
            for(int i = 0; i < n; i++){
                colSum += grid[i][j];
                partial[(long long)grid[i][j]]++;
            }
            long long leftSum = colSum;
            long long rightSum = totSum - leftSum;
            
            if(leftSum == rightSum) return true;
            else if(leftSum > rightSum){
                long long diff = leftSum - rightSum;
                if(n == 1){
                    if(j > 0){
                        if(grid[0][0] == diff || grid[0][j] == diff) return true;
                    }
                } else {
                    if(j == 0){
                        if(grid[0][0] == diff || grid[n-1][0] == diff) return true;
                    } else {
                        if(partial.count(diff)) return true;
                    }
                }
            } else {
                long long diff = rightSum - leftSum;
                if(n == 1){
                    if(j < m-2){
                        if(grid[0][m-1] == diff || grid[0][j+1] == diff) return true;
                    }
                } else {
                    if(j == m-2){
                        if(grid[0][m-1] == diff || grid[n-1][m-1] == diff) return true;
                    } else {
                        int pCount = partial.count(diff) ? partial[diff] : 0;
                        if(allEl.count(diff) && (allEl[diff] - pCount) > 0) return true;
                    }
                }
            }
        }
        return false;
    }
};


int main (){

    
    return 0;
}