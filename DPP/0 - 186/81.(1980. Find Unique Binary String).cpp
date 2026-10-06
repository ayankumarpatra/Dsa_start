#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        int n = nums.size();

        // start with a binary string of all 0
        string candidate(n, '0');

        // store all given strings in a set for quick lookup
        unordered_set<string> existing_strings;

        for (auto str : nums) {
            existing_strings.insert(str);
        }

        // keep generating next binary string until we find one not in the set
        while (existing_strings.find(candidate) != existing_strings.end()) {

            // increase the binary number
            candidate[0]++;

            for (int i = 0; i < n; i++) {

                // if digit becomes greater than 1, carry forward
                if (candidate[i] > '1') {
                    candidate[i] = '0';
                    candidate[i + 1]++;
                }
                else {
                    // stop when no carry is needed
                    break;
                }
            }
        }

        // this binary string does not exist in nums
        return candidate;
    }
};


int main (){

    
    return 0;
}