#include<iostream>
#include<climits>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int maxval=INT_MIN;

        for (int i=0;i<nums.size();i++){
            if (maxval<nums[i]){
                maxval=nums[i];
            }
        }

        vector<int> returnvect;

        for (int i=0;i<nums.size();i++){
            if (nums[i]<=maxval){
                returnvect.push_back(nums[i]);
            }
        }

        return returnvect;
    }
};

// approach 2 

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return nums;

        vector<bool> isValid(n, false);
        isValid[0] = true;
        isValid[n - 1] = true;

        int max_left = nums[0];
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] > max_left) {
                isValid[i] = true;
            }
            max_left = max(max_left, nums[i]);
        }

        int max_right = nums[n - 1];
        for (int i = n - 2; i > 0; --i) {
            if (nums[i] > max_right) {
                isValid[i] = true;
            }
            max_right = max(max_right, nums[i]);
        }

        vector<int> returnvect;
        for (int i = 0; i < n; ++i) {
            if (isValid[i]) {
                returnvect.push_back(nums[i]);
            }
        }

        return returnvect;
    }
};

int main (){

    
    return 0;
}