#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {

        int n = nums.size();

        long long result = -4e18;
        long long prefix_sum = nums[0];

        int left = 0;   // start of current window
        int peak = -1;  // index of first peak
        int valley = -1;// index of valley

        for (int right = 1; right < n; right++) {

            prefix_sum += nums[right];

            // equal breaks strict pattern -> restart window
            if (nums[right-1] == nums[right]) {
                left = right;
                prefix_sum = nums[right];
                peak = valley = -1;
            }

            // possible peak (start of decreasing)
            else if (nums[right-1] > nums[right]) {

                if (right > 1 && nums[right-2] < nums[right-1]) {

                    peak = right-1;

                    // remove extra left elements
                    while (left < valley) {
                        prefix_sum -= nums[left++];
                    }

                    // drop negative prefix (kadane style)
                    while (left < peak-1 && nums[left] < 0) {
                        prefix_sum -= nums[left++];
                    }
                }
            }

            // increasing again -> possible valley completed
            else {

                if (right > 1 && nums[right-2] > nums[right-1]) {
                    valley = right-1;
                }

                // valid trionic found
                if (left < peak && peak < valley) {
                    result = max(result, prefix_sum);
                }
            }
        }

        return result;
    }
};




int main (){

    
    return 0;
}