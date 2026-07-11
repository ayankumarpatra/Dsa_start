#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


class Solution {
public:
    bool checkOnesSegment(string s) {
        
        int ones_segment_count = 0;   // counts how many separate groups of 1 exist
        int index = 0;
        int n = s.length();

        // traverse the string
        while (index < n) {

            // if we find a 1, it means a new segment of ones may start
            if (s[index] == '1') {

                ones_segment_count++;   // found a new segment of ones

                // move forward until the current segment of 1s ends
                while (index < n && s[index] == '1') {
                    index++;
                }

            } 
            else {
                // if current char is 0, simply move forward
                index++;
            }
        }

        // if there is more than one segment of ones , return false
        // otherwise return true
        return ones_segment_count <= 1;
    }
};

int main (){

    
    return 0;
}