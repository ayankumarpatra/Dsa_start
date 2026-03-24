#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    typedef long long ll;
    
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;
        
        vector<vector<int>> ans(n, vector<int>(m));
        ll currproduct = 1;

        // 1. Prefix Product
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = currproduct; 
                // Multiply by current grid value for the NEXT cell's prefix
                currproduct = (currproduct * grid[i][j]) % mod;
            }
        }

        currproduct = 1; // reset for the Suffix

        // 2 suffix Product
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                // Multiply existing prefix by the suffix
                ans[i][j] = (ans[i][j] * currproduct) % mod;
                // Update suffix product for the next
                currproduct = (currproduct * grid[i][j]) % mod;
            }
        }

        return ans;
    }
};


int main (){

    
    return 0;
}