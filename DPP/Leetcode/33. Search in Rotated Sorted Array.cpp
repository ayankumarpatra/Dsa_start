#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int start = 0 , end = nums.size()-1 , mid;

        while (start <= end)
        {
            mid = start + (end - start)/2;

            if (nums[mid]==target){ // if the curr idx is the target , return 
                return mid;
            }

            /*
            else check the left side if sorted and element may there ; see left side will be sorted for sure
            sorted in ascending order and possibly left rotated at an unknown index
            */
            
            else if ( target>=nums[start] && target<= nums[mid] ){
                end = mid - 1;
            }

            else {
                start = mid + 1;
            }
        }


        return -1;
        
    }
};


int main (){

    
    return 0;
}