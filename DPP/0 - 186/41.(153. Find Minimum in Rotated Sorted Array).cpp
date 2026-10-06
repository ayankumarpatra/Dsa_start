#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0;

        while (i<nums.size()-2)
        {
            if(nums[i]>nums[i+1]){
                return nums[i+1];
            }
            i++;
        }

        return nums[0];
        
    }
};



int main (){

    
    return 0;
}