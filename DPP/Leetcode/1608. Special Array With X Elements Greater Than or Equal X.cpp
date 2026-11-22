#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort (nums.begin(),nums.end());

        int numidx = 0 , max_val = nums[nums.size()-1];
        

        for (int i = 0 ; i<max_val ; i++){

            if (nums[numidx] == 0) {  // getting the first non zero idx , but keeping i constant to check
                // fot the values lower than arr[0] if applicable 
                numidx ++;
                i--;
                continue;
            }

            if (numidx<nums.size() ){ 
                // we can get elements till the last index

                if ( i<= nums[numidx] ){
                    if (i == nums.size() - numidx ){
                        return i;
                    }

                    else if (nums[numidx] == nums.size() - numidx ){
                        return nums[numidx];
                    }
                }
                else{
                    numidx++;
                    i--;
                }
            }
        }

        return -1;
    }
};

int main (){

    
    return 0;
}