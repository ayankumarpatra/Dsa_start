#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        /*
        floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x. If no floor or ceil exists, output -1.
        */

        int floor=-1,ceiling=-1;

        for (int currnum : nums){
            if (currnum<=x){
                floor=currnum;
            }
            if (currnum>= x && (currnum<ceiling || ceiling==-1)){
                ceiling = currnum;
            }
        }

        return {floor,ceiling};
    }
};



// or the binary search approach 

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        // as said array is sorted so use binary search to find the curr idx , then doing other things 

        int low =0 , high = nums.size()-1;

        int mid=0;

        int floor=-1,ceiling=-1;

        while (low<=high)
        {
            mid = low + (high - low)/2;

            if (nums[mid]==x){ // finding the numbers idx
                return {x,x};
            }

            else if (nums[mid]>x){
                ceiling = nums[mid];
                high = mid-1;
            }
            else {
                floor = nums[mid];
                low = mid +1;
            }
        }
        
        return {floor,ceiling};
        
    }
};

int main (){

    
    return 0;
}