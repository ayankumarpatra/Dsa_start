#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        
        // if string length is smaller than k, impossible
        if (n < k) 
            return false;

        int total_needed = 1 << k;   // total possible binary codes = 2^k
        vector<bool> visited(total_needed, false);

        int mask = total_needed - 1; // keeps only last k bits
        int current_hash = 0;

        for (int i = 0; i < n; i++) {

            // left shift by 1 (multiply by 2)
            // remove extra bits using mask
            // add current bit at right
            current_hash = ((current_hash << 1) & mask) | (s[i] - '0');

            // only start checking when window size becomes k
            if (i >= k - 1) {

                // if this binary code not seen before
                if (!visited[current_hash]) {
                    visited[current_hash] = true;
                    total_needed--;  // decrease count of remaining codes

                    // if all codes found
                    if (total_needed == 0)
                        return true;
                }
            }
        }

        return false;  // some codes missing
    }
};

int main (){

    
    return 0;
}