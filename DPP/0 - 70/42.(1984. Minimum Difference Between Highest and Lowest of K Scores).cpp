#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std ;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (nums.size()==1 || k==1){// only 1 means directly return that
            return 0;
        }
       
        sort(nums.begin(),nums.end());
        int mindiff=INT_MAX;
        int maxlen=nums.size();
        k--;// as array index start by 0 so if size 2 then for array its 0 ,1
       
        for (int i=0;k<maxlen;i++){
            mindiff=min(mindiff,nums[k]-nums[i]);
            k++;
        }
       
       return mindiff;
    }
};

int main (){

    
    return 0;
}