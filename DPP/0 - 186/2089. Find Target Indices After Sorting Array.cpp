#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        // first sorting the arr

        sort (nums.begin(),nums.end());

        int low = 0 , high = nums.size()-1 , mid ;

        int left_idx = -1 , right_idx = -1;

        vector <int> return_vect;

        while (low <= high) // finding the leftmost idx 
        {
            mid = low + (high - low)/2;

            if (nums[mid]==target){
                left_idx = mid;
                high = mid-1 ; // to keep explore the left half 
            }

            else if (nums[mid] < target){
                low = mid +1;
            }

            else {
                high = mid -1;
            }
        }
        
        
        if (left_idx == -1){ //  means no element exist 
            return return_vect;
        }
        
        // now searching the rightmost idx 

        low = left_idx +1;
        high = nums.size()-1;

        while (low <= high)
        {
            mid = low + ( high - low )/2;

            if (nums[mid] == target){
                right_idx = mid;
                low = mid + 1;
            }

            else if ( nums[mid] < target){
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }
        return_vect.push_back(left_idx);
        
        if (right_idx != -1){
            for (int i = left_idx+1 ; i<=right_idx ; i++ ){
                return_vect.push_back(i);
            }
        }

        return return_vect;
    }
};


int main (){

    
    return 0;
}