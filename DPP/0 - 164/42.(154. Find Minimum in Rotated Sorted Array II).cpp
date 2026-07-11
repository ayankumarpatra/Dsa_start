#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size()<2){
            return nums[0];
        }
        int low=0;
        int high=nums.size()-1;

        while (low<high)
        {
            if (nums[low]>nums[low+1]){
                return nums[low+1];
            }
            else if (nums[high]<nums[high-1]){
                return nums[high-1];
            }
        }
        return nums[0];
    }
};



int main (){

    
    return 0;
}