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

            if ( nums [mid] == target ){
                return mid;
            }

            // check if the left half is sorted
            
            if (nums[start] < nums[mid])
            {
                if (nums[mid] < target){
                    start = mid +1;
                }

                else {
                    end = mid -1;
                }
            }

            // else check if the right half is sorted

            else {
                if (nums[mid] < target){
                    start = mid +1;
                }

                else {
                    end = mid -1;
                }
            }
            
        }

        return -1;
        
    }
};


int main (){

    
    return 0;
}