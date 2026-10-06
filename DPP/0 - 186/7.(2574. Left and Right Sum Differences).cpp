#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector <int> returnvect (nums.size(), 0);

        int leftsum=0,rightsum=0;

        vector<int> leftarr(nums.size(),0);
        vector<int> rightarr(nums.size(),0);

        int leftidx=nums.size()-1;
        for (int i=0;i<nums.size();i++){

            leftarr[leftidx]=leftsum;
            rightarr[i]=rightsum;

            leftsum+= nums[leftidx];
            rightsum+= nums[i];

            leftidx-=1;

        }
        for (int i=0;i<nums.size();i++){
            returnvect[i]=abs(leftarr[i]-rightarr[i]);
        }

        return returnvect;
    }
};



int main (){

    
    return 0;
}