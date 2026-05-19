#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n=nums.size();
        const int max_val = 1 << 14;
        vector<int> dp(max_val, -1);
        dp[0] = 0;

        for (int x : nums) {
            vector<int> dp2 = dp;
            for (int xor_value = 0; xor_value < max_val; xor_value++) {
                if (dp[xor_value] == -1){
                    continue;
                }
                int new_xor = xor_value ^ x;
                if (new_xor < max_val)
                    dp2[new_xor] = max(dp2[new_xor], dp[xor_value] + 1);
            }
            dp = dp2;
        }
        if (dp[target] == -1) return -1;
        return n - dp[target];
    }
};

int main (){

    
    return 0;
}