#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while (i > 0 && nums[i-1] >= nums[i]) {
            i--;
        }
        
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int j = nums.size() - 1;
        while (j >= i && nums[j] <= nums[i-1]) {
            j--;
        }
        
        swap(nums[i-1], nums[j]);
        reverse(nums.begin() + i, nums.end());        
    }
};


// retry 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() -1;

        while (i>0 && nums[i-1] >= nums[i])// till the prev number is greater or equal to curr number
        {
            i -- ;
        }
        
        // if i=0 means the whole arr is sorted as see if its [3,2,1] then [1,2,3] 
        // because [3,2,1] does not have a lexicographical larger rearrangement.

        if (i == 0 ){
            reverse ( nums.begin() , nums.end());
            return ; 
        }


        // else find the next largest index 

        int j = nums.size()-1;

        while (j>=i && nums[j]<=nums[i-1])
        {
            j--;
        }
        
        // swap the numbers 
        swap ( nums[i-1] , nums[j]);

        // reverse the remaining 

        reverse (nums.begin()+i , nums.end());
    }
};


int main (){

    
    return 0;
}