#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    int findMin(vector<int>& nums) {
        // normal trying 

        int minval = INT_MAX;

        int low = 0 , high = nums.size() -1 ;
        int mid ;

        while (low < high)
        {
            int mid = low + (high - low)/2;

            minval = min ( minval , nums[mid] );

            // check if left side is sorted 

            if ( nums[low] <= nums[mid] ){
                high = mid ;
            }
            else{
                low = mid + 1 ;
            }
        }

        return nums[low]; // same as high as how = high
        
    }
};


int main (){

    
    return 0;
}