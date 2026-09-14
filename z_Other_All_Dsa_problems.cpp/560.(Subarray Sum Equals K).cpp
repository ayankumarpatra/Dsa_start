#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count=0,currsum=0;
        // brutefore , only bruteforce :) no knight thinking at first

        for (int i=0;i<nums.size();i++){
            currsum=0;
        for (int j=i;j<nums.size();j++){
            currsum+=nums[i];
            if (currsum==k){
                count++;
            }
            else if(currsum>k){
                break;
            }
         }
        }

        return count;
    }
};



int main (){

    
    return 0;
}