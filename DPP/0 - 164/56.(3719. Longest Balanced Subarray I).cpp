#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;


class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        unordered_map<int, int> firstindex;
        int prefix = 0;
        int ans = 0;

        firstindex[0] = -1;
        for(int i = 0; i < nums.size(); i++){

            if(nums[i] % 2 == 0)
                prefix -= 1;
            else
                prefix += 1;

            if(firstindex.count(prefix)){
                ans = max(ans, i - firstindex[prefix]);
            }
            else{
                firstindex[prefix] = i;
            }
        }

        return ans;
    }
};


int main (){

    
    return 0;
}