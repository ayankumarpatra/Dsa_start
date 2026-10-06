#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std ;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int curr_sum= nums[0], max_sum=nums[0];

        for (int i=0;i<nums.size();i++){

            curr_sum+=nums[i];

            if (curr_sum>max_sum){
                max_sum=curr_sum;
            }
            else if (curr_sum<max_sum){
                curr_sum=0;
            }
        }

        return max_sum;
    }
};


int main (){

    
    return 0;
}