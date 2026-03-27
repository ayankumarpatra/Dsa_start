#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        // traverse from rightmost bit to second bit and stop before index 0 because final result should be 1
        for (int i = s.size() - 1; i > 0; i--) {

            // curr bit value including carry
            int bit = (s[i] - '0') + carry;

            if (bit % 2 == 0) {
                // even just divide by 2
                steps += 1;
            } else {
                // odd add 1 then divide
                steps += 2;
                carry = 1;  // after adding 1, carry remains
            }
        }

        // if carry remains at most significant bit
        if (carry == 1)
            steps += 1;

        return steps;
    }
};


int main (){

    
    return 0;
}