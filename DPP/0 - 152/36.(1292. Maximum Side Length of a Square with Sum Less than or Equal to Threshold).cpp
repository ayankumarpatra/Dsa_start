#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

#include <vector>
using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();   
        int n = mat[0].size(); 
        
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = mat[i-1][j-1] 
                                + prefixSum[i-1][j]     
                                + prefixSum[i][j-1]    
                                - prefixSum[i-1][j-1];  
            }
        }
        
        int maxSide = 0; 

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                for (int size = maxSide + 1; i + size - 1 <= m && j + size - 1 <= n; size++) {

                    int x = i + size - 1;
                    int y = j + size - 1;
                    

                 int sum = prefixSum[x][y] 
                            - prefixSum[i-1][y]     
                            - prefixSum[x][j-1]     
                            + prefixSum[i-1][j-1];  
                    
                    if (sum <= threshold) {
                        maxSide = size;
                    } else {
                        break;
                    }
                }
            }
        }
        
        return maxSide;
    }
};



int main (){

    
    return 0;
}