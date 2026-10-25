#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0 , high = nums.size() -1 ;
        int mid = 0;

        while (low <= high)
        {
            int mid = low + (high -low)/2;

            if (nums [mid] == target){
                return true;
            }

            // else first check if any half is sorted or not if not then shrink the whole search window 

            if (nums[low] == nums[mid] && nums[mid] == nums[high]){
                low ++;
                high --;
                continue;
            }

            // else check if the left side sorted 
            // eg low -> mid

            else if ( nums [low] <= nums[mid] ){
                if ( nums[low]<= target && target <= nums[mid] ){
                    // move end to left side 
                    high = mid -1;
                }
                else{
                    low = mid + 1;
                }
            }

            // else the right side must be sorted 
            else {
                // check if it exists on which side 
                if (target>= nums[mid] && target<= nums[high]){
                    low = mid +1;
                }
                else{
                    high = mid -1;
                }
            }
        }

        return false;
        
    }
};

int main (){

    
    return 0;
}