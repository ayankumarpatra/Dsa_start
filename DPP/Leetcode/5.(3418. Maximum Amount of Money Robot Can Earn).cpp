#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, 0))
        );

        dp[0][0][0] = coins[0][0];

        if(coins[0][0]> 0){
            dp[0][0][1] =coins[0][0];
            dp[0][0][2] = coins[0][0];
        }

        for(int i=0;i<m; i++){
            for(int j=0; j<n;j++){
                for(int rem=0;rem<3; rem++){

                    if(i==0 && j==0) {
                        continue;
                        }

                    int up = -1e9, left = -1e9;

                    if(i > 0){
                        up = coins[i][j] + dp[i-1][j][rem];

                        if(coins[i][j] < 0 && rem){
                            up = max(up, dp[i-1][j][rem-1]);
                        }
                    }

                    if(j > 0){
                        left = coins[i][j] + dp[i][j-1][rem];

                        if(coins[i][j] < 0 && rem){
                            left = max(left, dp[i][j-1][rem-1]);
                        }
                    }
                    dp[i][j][rem] = max(up, left);
                }
            }
        }

        return dp[m-1][n-1][2];
    }
};


int main (){

    
    return 0;
}