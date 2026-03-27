#include<iostream>
#include<stack>
#include<vector>
#include <algorithm>

using namespace std ;



class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        const int rows = grid.size();
        const int cols = grid[0].size();
        const int total_cells = rows * cols;
        const int INF = 1e9 + 7;

        // find the maximum value in the grid to size our value tracking arrays
        int max_grid_val = 0;
        for (const auto& row : grid) {
            for (int val : row) max_grid_val = max(max_grid_val, val);
        }

        // group cell indices by their grid values
        // valueindices[v] contains all (i*cols + j) where grid[i][j] == v
        vector<vector<int>> value_to_indices(max_grid_val + 1);
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                value_to_indices[grid[r][c]].push_back(r * cols + c);
            }
        }

        // dp[t][cell_idx] = min cost to reach cell_idx using at most 't' teleports
        vector<vector<unsigned int>> dp(k + 1, vector<unsigned int>(total_cells, INF));

        // layer 0:(0 Teleports)
        dp[0][0] = 0; // starting cell cost is 0 (or grid[0][0] depending on rules, 
                      // but here we start AT 0,0 so we don't pay for it yet)
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int curr = r * cols + c;
                if (r > 0) dp[0][curr] = min(dp[0][curr], dp[0][(r - 1) * cols + c] + grid[r][c]);
                if (c > 0) dp[0][curr] = min(dp[0][curr], dp[0][r * cols + (c - 1)] + grid[r][c]);
            }
        }

        // layers 1 to K: pathfinding with tleportation ---
        for (int t = 1; t <= k; ++t) {
            vector<unsigned int> best_cost_from_value_ge(max_grid_val + 1, INF);
            unsigned int running_min = INF;

            // precompute suffix minimums: 
            // What is the best cost to reach any cell with value >= V?
            for (int v = max_grid_val; v >= 0; --v) {
                for (int cell_idx : value_to_indices[v]) {
                    running_min = min(running_min, dp[t - 1][cell_idx]);
                }
                best_cost_from_value_ge[v] = running_min;
            }

            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    int curr = r * cols + c;
                    int val = grid[r][c];

                    // option: don't use a new teleport (carry over previous best)
                    dp[t][curr] = dp[t - 1][curr];

                    // option 2: teleport here from a cell with value >= current val
                    // this costs 0, so we just take the best cost from the previous layer
                    dp[t][curr] = min(dp[t][curr], best_cost_from_value_ge[val]);

                    // option 3: standard move (Down/Right) using current teleport allowance
                    if (r > 0) dp[t][curr] = min(dp[t][curr], dp[t][(r - 1) * cols + c] + val);
                    if (c > 0) dp[t][curr] = min(dp[t][curr], dp[t][r * cols + (c - 1)] + val);
                }
            }
        }

        return dp[k][total_cells - 1];
    }
};


int main (){

    
    return 0;
}