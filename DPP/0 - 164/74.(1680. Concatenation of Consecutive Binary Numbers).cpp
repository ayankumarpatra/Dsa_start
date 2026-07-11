#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


#define MOD 1000000007

class Solution {
public:
    int concatenatedBinary(int n) {

        long long result = 0;
        int bit_length = 0;

        for (int i = 1; i <= n; ++i) {

            // if i is power of 2, increase bit length
            if ((i & (i - 1)) == 0)
                bit_length++;

            // shift and add
            result = ((result << bit_length) % MOD + i) % MOD;
        }

        return (int)result;
    }
};


int main (){

    
    return 0;
}