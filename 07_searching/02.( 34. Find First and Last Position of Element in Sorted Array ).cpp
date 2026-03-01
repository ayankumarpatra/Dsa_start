#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();

        if (n == 0) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        // First binary search → find first position
        int low = 0, high = n - 1;
        int first = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;  // keep searching left
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // If not found, return [-1, -1]
        if (first == -1) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(first);

        // Second binary search → find last position
        low = first;       // optimization: we know first occurrence
        high = n - 1;
        int last = first;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;  // keep searching right
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        ans.push_back(last);

        return ans;
    }
};


int main (){

    
    return 0;
}