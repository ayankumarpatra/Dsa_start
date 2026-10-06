#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int bitwiseComplement(int n) {

        // special case: complement of 0 is 1
        if (n == 0)
            return 1;

        // find how many bits are needed to represent n
        int bit_count = floor(log2(n)) + 1;

        // create a mask with all bits set to 1
        // eg if bit count = 3 mask = 111
        int all_ones_mask = pow(2, bit_count) - 1;

        // xor with mask flips all bits
        int result = n ^ all_ones_mask;

        return result;
    }
};


int main (){

    
    return 0;
}