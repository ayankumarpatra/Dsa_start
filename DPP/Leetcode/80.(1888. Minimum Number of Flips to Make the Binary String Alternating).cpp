#include<iostream>
#include<climits>
#include<vector>

using namespace std ;

class Solution {
public:
    int minFlips(string s) {

        int n = s.length();
        string doubled = s + s;   // simulate rotations

        int mismatch_pattern1 = 0;   // for pattern 010101...
        int mismatch_pattern2 = 0;   // for pattern 101010...

        int left = 0;
        int min_flips = INT_MAX;

        for (int right = 0; right < doubled.length(); right++) {

            // expected characters for alternating patterns
            char expected1 = (right % 2 == 0) ? '0' : '1';
            char expected2 = (right % 2 == 0) ? '1' : '0';

            if (doubled[right] != expected1)
                mismatch_pattern1++;

            if (doubled[right] != expected2)
                mismatch_pattern2++;

            // shrink window if size exceeds original length
            if (right - left + 1 > n) {

                char left_expected1 = (left % 2 == 0) ? '0' : '1';
                char left_expected2 = (left % 2 == 0) ? '1' : '0';

                if (doubled[left] != left_expected1)
                    mismatch_pattern1--;

                if (doubled[left] != left_expected2)
                    mismatch_pattern2--;

                left++;
            }

            // when window size becomes n, update answer
            if (right - left + 1 == n) {
                min_flips = min(min_flips, min(mismatch_pattern1, mismatch_pattern2));
            }
        }

        return min_flips;
    }
};


int main (){

    
    return 0;
}