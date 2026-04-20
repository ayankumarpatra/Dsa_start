#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int tempsum=0;
        vector<int> sumreturn(nums.size(),0);

        for (int i=0;i<nums.size();i++){
            tempsum+=nums[i];
            sumreturn[i]=tempsum;
        }

        return sumreturn;
    }
};

// experimenting 

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int tempsum=0;

        for (int i=0;i<nums.size();i++){
            tempsum+=nums[i];
            nums[i]=tempsum;
        }

        return nums;
    }
};

int main (){

    
    return 0;
}