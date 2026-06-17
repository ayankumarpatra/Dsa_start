#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    char processStr(string s, long long k) {
        
        //track sizes only, dont build the string
        vector<long long> sizes;
        long long sz = 0;
        long long cap = 2e15; // prevent overflow; after this k can never be out of range

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                if (sz > 0) sz--;
            }
            else if (s[i] == '#') {
                sz = min(sz * 2, cap);
            }
            else if (s[i] == '%') {
                // size dont change, nothing to do
            }
            else {
                sz++;
            }
            sizes.push_back(sz); // remember size after each step
        }

        // if k is beyond final size, return '.'
        if (k >= sz) return '.';

        // STEP 2: go backwards, updating k
        for (int i = s.size() - 1; i >= 0; i--) {
            long long prevsize = (i == 0) ? 0 : sizes[i - 1];

            if (s[i] == '#') {
                // string was doubled: second half is copy of first half
                k = k % prevsize;
            }
            else if (s[i] == '%') {
                // string was reversed
                k = sizes[i] - 1 - k;
            }
            else if (s[i] == '*') {
                // last char was deleted, k is unaffected eg if k=10 it still k 10 only string size changes 
            }
            else {
                // a regular char was appended at position prevsize
                if (k == prevsize) {
                    return s[i]; // this is ans
                }
                // else k is somewhere before this char,keep going back
            }
        }

        return '.'; // shouldnt reach here
    }
};

int main (){

    
    return 0;
}