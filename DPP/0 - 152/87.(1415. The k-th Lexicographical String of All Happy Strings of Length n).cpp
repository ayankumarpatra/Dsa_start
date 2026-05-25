#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


class Solution {
public:
    string getHappyString(int n, int k) {

        // total happy strings possible
        int total_strings = 3 * (1 << (n - 1));

        // if k exceeds possible strings
        if (k > total_strings)
            return "";

        vector<char> letters = {'a', 'b', 'c'};
        string result = "";

        // convert to 0-index
        k--;

        // size of block for first character
        int block_size = (1 << (n - 1));

        // choose first character
        result += letters[k / block_size];

        k %= block_size;

        // fill remaining positions
        for (int i = n - 2; i >= 0; i--) {

            vector<char> next_choices;

            // choose characters different from previous
            for (char c : letters) {
                if (c != result.back())
                    next_choices.push_back(c);
            }

            block_size = (1 << i);

            // select next character
            result += next_choices[k / block_size];

            k %= block_size;
        }

        return result;
    }
};

int main (){

    
    return 0;
}