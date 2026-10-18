#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low_idx=0,high_idx=nums.size()-1;
        int mid;
        while (low_idx<=high_idx)
        {
            mid = low_idx+ (high_idx-low_idx)/2;

            if (nums[mid]==target){
                return mid;
            }
            else if (nums[mid]<target){
                low_idx=mid+1;
            }
            else{
                high_idx=mid-1;
            }
        }

        return -1;
        
    }
};


int main (){

    
    return 0;
}