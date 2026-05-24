#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> returnvect;
        if (nums.empty() || k<=0) return returnvect;

        int count = 0;

        for (int i =0; i < nums.size(); i++) {
            if (i== 0 ||nums[i]!=nums[i-1]) {
                count = 1;
            } else {
                count++;
            }
            if (count <=k) {
                returnvect.push_back(nums[i]);
            }
        }

        return returnvect;
    }
};


int main (){

    
    return 0;
}