#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // first getting the first occurance ; 
        // as sorted so this time i will cook by binary search

        int low = 0 , high = nums.size()-1;

        int mid , firstpos = -1 , lastpos = -1;

        while (low <= high)
        {
            mid = low + ( high - low )/2;

            if (nums[mid]==target) {
                firstpos = mid;
                high = mid - 1; // keep search the left half 
            }

            else if ( nums[mid] < target ){
                low = mid + 1;
            }

            else {
                high = mid -1;
            }
        }

        // if still firstpos =-1 means the element doesnt exist 

        if (firstpos == -1){
            return {-1,-1};
        }

        // else lets again search for the 2nd element 

        low = firstpos ;
        high = nums.size()-1;

        while (low <= high)
        {
            mid = low + ( high - low )/2;

            if (nums[mid]==target) {
                lastpos = mid;
                low = mid + 1; // keep search the right half 
            }

            else if ( nums[mid] < target ){
                low = mid + 1;
            }

            else {
                high = mid -1;
            }
        }

        return {firstpos,lastpos};
    }
};


int main (){

    
    return 0;
}