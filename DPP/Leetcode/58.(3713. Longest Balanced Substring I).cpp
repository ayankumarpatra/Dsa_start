#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int longestBalanced(string s) {

        int n = s.size();
        int longest_len = 0;   // stores answer

        // pick every index as starting point
        for(int start = 0; start < n; start++){

            vector<int> freq(26, 0); // frequency of a-z
            int unique_chars = 0;    // how many different letters
            int max_freq = 0;        // highest frequency of any letter

            // extend substring
            for(int end = start; end < n; end++){

                int char_index = s[end] - 'a';

                // if this letter appears first time
                if(freq[char_index] == 0){
                    unique_chars++;
                }

                // increase freq and update max
                freq[char_index]++;
                max_freq = max(max_freq, freq[char_index]);

                int current_len = end - start + 1;

                // check balanced condition
                if(current_len == unique_chars * max_freq){
                    longest_len = max(longest_len, current_len);
                }
            }
        }

        return longest_len;
    }
};



int main (){

    
    return 0;
}