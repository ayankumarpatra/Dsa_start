#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

/*

    nums[0...p] is strictly increasing,
    nums[p...q] is strictly decreasing,
    nums[q...n − 1] is strictly increasing.

*/

class Solution {
public:
    bool isTrionic(vector<int>& nums) {

        int n = nums.size();
        int i = 0;

        // increasing
        while(i < n-2 && nums[i] < nums[i+1]) {
            i++;
        }

        if(i == 0) return false; // no increasing

        //decreasing
        int j = i;
        while(j < n-1 && nums[j] > nums[j+1]) {
            j++;
        }

        if(j == i || j == n-1) return false; 
        // no decreasing no third part

        // increasing
        while(j < n-1 && nums[j] < nums[j+1]) {
            j++;
        }

        return j == n-1;
    }
};



int main (){

    
    return 0;
}