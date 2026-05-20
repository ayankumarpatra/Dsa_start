#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
        3 steps
        1. find the pivot element where transition is happening right to left
        2. now after the pivot till the last element reverse the arr
        3. now swap pivot idx, pivot idx+1


        [1, 3, 5, 4, 2]

        Step 1: scan right to left → 2<4? no. 4<5? no. 3<5? YES → pivot = index 1 (value 3)

        Step 2: find smallest number > 3 in [5,4,2] → that's 4 → swap
                → [1, 4, 5, 3, 2]

        Step 3: reverse everything after index 1
                → [1, 4, 2, 3, 5] 
        */


        // scanning right to left and get the pivot index

        int index=0;

        for (int i=nums.size()-1;i>0;i--){
            if (nums[i-1]<nums[i]){
                index=i;
                break;
            }
        }

        swap()


    }
};



int main (){

    
    return 0;
}