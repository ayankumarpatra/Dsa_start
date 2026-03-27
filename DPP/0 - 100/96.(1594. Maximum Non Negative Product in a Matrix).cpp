#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;

        // using long long to prevent overflow
        vector<vector<long long>> max_p(m, vector<long long>(n));
        vector<vector<long long>> min_p(m, vector<long long>(n));

        // 1. start
        max_p[0][0] = min_p[0][0] = grid[0][0];

        // 2. fill first column 
        for (int i = 1; i < m; i++) {
            max_p[i][0] = min_p[i][0] = max_p[i-1][0] * grid[i][0];
        }

        // 3. fill first row
        for (int j = 1; j < n; j++) {
            max_p[0][j] = min_p[0][j] = max_p[0][j-1] * grid[0][j];
        }

        // 4. fill the rest of the grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == 0) {
                    max_p[i][j] = min_p[i][j] = 0;
                } else {
                    // Possible val from top and left
                    long long a = max_p[i-1][j] * grid[i][j];
                    long long b = min_p[i-1][j] * grid[i][j];
                    long long c = max_p[i][j-1] * grid[i][j];
                    long long d = min_p[i][j-1] * grid[i][j];

                    max_p[i][j] = max({a, b, c, d});
                    min_p[i][j] = min({a, b, c, d});
                }
            }
        }

        long long finalAns = max_p[m-1][n-1];
        
        // If the best product is negative,return -1
        return (finalAns < 0) ? -1 : (finalAns % MOD);
    }
};


int main (){

    
    return 0;
}