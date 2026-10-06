#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {

        const int mod = 1000000007;
        int limit_block = limit + 1;

        // dp tables
        // dp_end_zero[i][j] arrays with i zeros and j ones ending with 0
        // dp_end_one[i][j]  arrays with i zeros and j ones ending with 1
        vector<vector<long long>> dp_end_zero(zero + 1, vector<long long>(one + 1, 0));
        vector<vector<long long>> dp_end_one(zero + 1, vector<long long>(one + 1, 0));

        // initialize sequences that contain only zeros
        for (int i = 1; i <= min(zero, limit); i++) {
            dp_end_zero[i][0] = 1;
        }

        // initialize sequences that contain only ones
        for (int j = 1; j <= min(one, limit); j++) {
            dp_end_one[0][j] = 1;
        }

        // fill dp tables
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {

                // build arrays ending with zero
                dp_end_zero[i][j] =
                    (dp_end_zero[i - 1][j] + dp_end_one[i - 1][j]) % mod;

                if (i >= limit_block) {
                    dp_end_zero[i][j] =
                        (dp_end_zero[i][j] - dp_end_one[i - limit_block][j] + mod) % mod;
                }

                // build arrays ending with one
                dp_end_one[i][j] =
                    (dp_end_zero[i][j - 1] + dp_end_one[i][j - 1]) % mod;

                if (j >= limit_block) {
                    dp_end_one[i][j] =
                        (dp_end_one[i][j] - dp_end_zero[i][j - limit_block] + mod) % mod;
                }
            }
        }

        // total stable arrays
        return (dp_end_zero[zero][one] + dp_end_one[zero][one]) % mod;
    }
};


int main (){

    
    return 0;
}