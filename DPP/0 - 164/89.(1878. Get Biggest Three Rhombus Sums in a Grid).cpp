#include<iostream>
#include<set>
#include<vector>

using namespace std ;

class solution {
public:
    vector<int> get_biggest_three(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // a set automatically keeps elements unique and 'greater<int>' keeps them sorted descending
        set<int, greater<int>> unique_rhombus_sums;

        for (int row_idx = 0; row_idx < rows; row_idx++) {
            for (int col_idx = 0; col_idx < cols; col_idx++) {
                
                // every single cell is technically a rhombus of size 0
                unique_rhombus_sums.insert(grid[row_idx][col_idx]);

                // calculate the maximum possible side length (size) for a rhombus 
                // starting at (row_idx, col_idx) as the top vertex
                int max_possible_size = min((rows - row_idx - 1) / 2, min(col_idx, cols - col_idx - 1));

                for (int size = 1; size <= max_possible_size; size++) {
                    int current_rhombus_sum = 0;

                    // 1. traverse from top vertex down to the left vertex
                    for (int offset = 0; offset <= size; offset++)
                        current_rhombus_sum += grid[row_idx + offset][col_idx - offset];
                    
                    // 2. traverse from top vertex down to the right vertex
                    // (start offset at 1 to avoid double-counting the top vertex)
                    for (int offset = 1; offset <= size; offset++)
                        current_rhombus_sum += grid[row_idx + offset][col_idx + offset];
            
                    // 3. traverse from the left vertex down to the bottom vertex
                    // (start offset at 1 to avoid double-counting the left vertex)
                    for (int offset = 1; offset <= size; offset++)
                        current_rhombus_sum += grid[row_idx + size + offset][col_idx - size + offset];
        
                    // 4. traverse from the right vertex down to the bottom vertex
                    // (offset ends at size-1 to avoid double-counting right and bottom vertices)
                    for (int offset = 1; offset < size; offset++)
                        current_rhombus_sum += grid[row_idx + size + offset][col_idx + size - offset];

                    unique_rhombus_sums.insert(current_rhombus_sum);
                }
            }
        }

        // extract the top 3 unique sums from the set
        vector<int> top_three_sums;
        auto it = unique_rhombus_sums.begin();
        for (int i = 0; i < 3 && it != unique_rhombus_sums.end(); i++) {
            top_three_sums.push_back(*it);
            it++;
        }

        return top_three_sums;
    }
};


int main (){

    
    return 0;
}