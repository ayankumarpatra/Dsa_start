#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // column_counts[j] stores the number of Xs and Ys found in column j
        // from the top row (0) down to the current row being processed.
        // .first represents X count, .second represents Y count.
        vector<pair<int, int>> column_counts(cols, {0, 0});
        
        int valid_submatrices_count = 0;

        for (int row_idx = 0; row_idx < rows; row_idx++) {
            // these variables track the total count for the submatrix 
            // ending at (row_idx, col_idx) starting from (0,0)
            int total_x_in_submatrix = 0;
            int total_y_in_submatrix = 0;

            for (int col_idx = 0; col_idx < cols; col_idx++) {
                // step 1 update vertical counts for the current column
                if (grid[row_idx][col_idx] == 'X') {
                    column_counts[col_idx].first++;
                } else if (grid[row_idx][col_idx] == 'Y') {
                    column_counts[col_idx].second++;
                }

                // step 2 accumulate vertical counts horizontally to get submatrix totals
                // this adds the entire vertical bar of counts for this column 
                // to our running horizontal total.
                total_x_in_submatrix += column_counts[col_idx].first;
                total_y_in_submatrix += column_counts[col_idx].second;

                // step 3 evaluate the submatrix based on problem constraints
                // - contains at least one X
                // - frequency of X and Y are equal
                if (total_x_in_submatrix >= 1 && total_x_in_submatrix == total_y_in_submatrix) {
                    valid_submatrices_count++;
                }
            }
        }

        return valid_submatrices_count;
    }
};

int main (){

    
    return 0;
}