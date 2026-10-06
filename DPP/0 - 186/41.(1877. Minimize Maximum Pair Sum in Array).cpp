#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std ;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int halfmax=nums.size()/2;
        int maxlen=nums.size()-1;
        int globalmax=INT_MIN;

        for(int i=0;i<halfmax;i++){
            globalmax=max(globalmax,nums[i]+nums[maxlen-i]);
        }

        return globalmax;
    }
};


int main (){

    
    return 0;
}