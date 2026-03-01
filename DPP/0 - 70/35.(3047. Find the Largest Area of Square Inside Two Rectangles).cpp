#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


#include <vector>
using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();    // number of rows
        int n = grid[0].size(); // number of columns
        
        // the maximum possible square size is the minimum of rows and columns
        int maxSize = min(m, n);

        for (int size = maxSize; size >= 2; size--) {
            // try all possible top-left corners for a square of this size
            for (int i = 0; i <= m - size; i++) {
                for (int j = 0; j <= n - size; j++) {
                    // check if the square starting at (i, j) with given size is magic
                    if (isMagic(grid, i, j, size)) {
                        return size; // found the largest, return immediately
                    }
                }
            }
        }
        
        return 1; // if no magic square found, return 1
    }
    
private:
    // helper function to check if a square is magic
    // (row, col) = top-left corner, size = side length of square
    bool isMagic(vector<vector<int>>& grid, int row, int col, int size) {
        // calculate the sum of the first row to use as reference
        int targetSum = 0;
        for (int j = col; j < col + size; j++) {
            targetSum += grid[row][j];
        }
        
        // check all rows
        for (int i = row; i < row + size; i++) {
            int rowSum = 0;
            for (int j = col; j < col + size; j++) {
                rowSum += grid[i][j];
            }
            if (rowSum != targetSum) {
                return false; // row sum doesn't match
            }
        }
        
        // check all columns
        for (int j = col; j < col + size; j++) {
            int colSum = 0;
            for (int i = row; i < row + size; i++) {
                colSum += grid[i][j];
            }
            if (colSum != targetSum) {
                return false; // column sum doesn't match
            }
        }
        
        // check main diagonal (top-left to bottom-right)
        int diagSum1 = 0;
        for (int i = 0; i < size; i++) {
            diagSum1 += grid[row + i][col + i];
        }
        if (diagSum1 != targetSum) {
            return false; // main diagonal sum doesn't match
        }
        
        // check anti-diagonal (top-right to bottom-left)
        int diagSum2 = 0;
        for (int i = 0; i < size; i++) {
            diagSum2 += grid[row + i][col + size - 1 - i];
        }
        if (diagSum2 != targetSum) {
            return false; // anti-diagonal sum doesn't match
        }
        
        // all checks passed so this is a magic square
        return true;
    }
};


int main (){

    
    return 0;
}