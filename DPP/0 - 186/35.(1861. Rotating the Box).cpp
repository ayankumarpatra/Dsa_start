#include<iostream>
#include<stack>
#include<vector>

using namespace std ;



class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // Step 1: Let the stones fall to the right in each row
        for (int i = 0; i < m; i++) {
            int lowestAvailable = n - 1; 
            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '#') {
                    // Move stone to the lowest available position
                    swap(boxGrid[i][j], boxGrid[i][lowestAvailable]);
                    lowestAvailable--;
                } else if (boxGrid[i][j] == '*') {
                    // Obstacle blocks everything; reset available position to the left of it
                    lowestAvailable = j - 1;
                }
                // If it's '.', we do nothing
            }
        }

        // Rotate the matrix 90 degrees clockwise
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotatedBox[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return rotatedBox;
    }
};



int main (){

    
    return 0;
}