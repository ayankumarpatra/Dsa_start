#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, ed = nums.size() - 1;

        while (st <= ed) {
            int mid = st + (ed - st) / 2;

            if (nums[mid] == target) return mid;

            // Check if the left half is sorted
            if (nums[st] <= nums[mid]) {
                if (nums[st] <= target && target < nums[mid]) {
                    ed = mid - 1;
                } else {
                    st = mid + 1;
                }
            } 
            // Otherwise, the right half must be sorted
            else {
                if (nums[mid] < target && target <= nums[ed]) {
                    st = mid + 1;
                } else {
                    ed = mid - 1;
                }
            }
        }

        return -1;
    }
};


int main (){

    
    return 0;
}