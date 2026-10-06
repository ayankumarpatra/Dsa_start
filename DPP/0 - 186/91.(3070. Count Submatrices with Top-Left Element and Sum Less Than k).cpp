#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        // step 1 create a matrix to store the cumulative sum (prefix sum)
        // prefix_sum_matrix[i][j] will store the sum of the submatrix from (0,0) to (i,j)
        vector<vector<int>> prefix_sum_matrix(rows, vector<int>(cols, 0));
        int valid_submatrix_count = 0;

        for (int row_idx = 0; row_idx < rows; row_idx++) {
            for (int col_idx = 0; col_idx < cols; col_idx++) {

                // start with the current cell value
                prefix_sum_matrix[row_idx][col_idx] = grid[row_idx][col_idx];

                // step 2 apply the inclusion-exclusion principle
                // to calculate the sum of the submatrix efficiently:
                // sum = current + top_region + left_region - overlapping_diagonal_region
                
                if (row_idx > 0) {
                    prefix_sum_matrix[row_idx][col_idx] += prefix_sum_matrix[row_idx - 1][col_idx];
                }
                
                if (col_idx > 0) {
                    prefix_sum_matrix[row_idx][col_idx] += prefix_sum_matrix[row_idx][col_idx - 1];
                }
                
                if (row_idx > 0 && col_idx > 0) {
                    // we subtract the top-left diagonal because it was added twice
                    // (once by the row_idx - 1 check and once by the col_idx - 1 check)
                    prefix_sum_matrix[row_idx][col_idx] -= prefix_sum_matrix[row_idx - 1][col_idx - 1];
                }

                // step 3 check if the calculated sum meets the condition
                if (prefix_sum_matrix[row_idx][col_idx] <= k) {
                    valid_submatrix_count++;
                } else {
                    // since all grid[i][j] >= 0, if the sum exceeds k, 
                    // expanding this specific submatrix further right won't help.
                    // we break the inner loop to save some time.
                    break; 
                }
            }
        }
        
        return valid_submatrix_count;
    }
};


int main (){

    
    return 0;
}