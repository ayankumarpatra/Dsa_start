#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int total_rows = matrix.size();
        int total_cols = matrix[0].size();

        // step 1 calculate consecutive heights of 1 s for each column
        // we transform each cell into the height of the vertical bar ending there
        for (int row_idx = 1; row_idx < total_rows; row_idx++) {
            for (int col_idx = 0; col_idx < total_cols; col_idx++) {
                if (matrix[row_idx][col_idx] == 1) {
                    // add the height from the cell directly above
                    matrix[row_idx][col_idx] += matrix[row_idx - 1][col_idx];
                }
            }
        }

        int max_submatrix_area = 0;

        // step 2 treat each row as a base for a histogram
        for (int row_idx = 0; row_idx < total_rows; row_idx++) {
            // we copy the current rows heights to sort them
            // sorting is allowed because we can rearrange columns freely
            vector<int> sorted_heights = matrix[row_idx];
            sort(sorted_heights.begin(), sorted_heights.end(), greater<int>());

            // step 3 calculate the largest possible area for this row base
            for (int col_idx = 0; col_idx < total_cols; col_idx++) {
                int current_height = sorted_heights[col_idx];
                int current_width = col_idx + 1; // width increases as we include more columns
                
                int current_area = current_height * current_width;
                max_submatrix_area = max(max_submatrix_area, current_area);
            }
        }

        return max_submatrix_area;
    }
};


int main (){

    
    return 0;
}