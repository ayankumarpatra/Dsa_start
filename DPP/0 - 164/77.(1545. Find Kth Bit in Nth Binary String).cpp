#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    char findKthBit(int n, int k) {
        
        int len = (1 << n) - 1;      // length of sn = 2^n - 1
        bool flip = false;           // track if we need to invert the bit
        
        while (k > 1) {              // keep reducing problem
            
            int mid = (len + 1) / 2; // middle position
            
            if (k == mid) {          // middle element is always '1'
                char ans = '1';
                if (flip) ans ^= 1;  // invert if flip flag is true
                return ans;
            }
            
            if (k > mid) {           // if k is in right half
                k = len - k + 1;     // move to mirrored position
                flip = !flip;        // right part is inverted
            }
            
            len = mid - 1;           // move to previous level string
        }
        
        // base case s1 = "0"
        char ans = '0';
        if (flip) ans ^= 1;          // apply inversion if needed
        
        return ans;
    }
};

int main (){

    
    return 0;
}