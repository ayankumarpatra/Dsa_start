#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    const int M = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        for(int i=0;i<q.size();i++){
            int l = q[i][0];
            int r = q[i][1];
            int k = q[i][2];
            int v = q[i][3];
            while(l<=r){
                nums[l] = (1LL*nums[l]*v)%M;
                l += k;
            }
        }
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            ans ^= nums[i];
        }
        return ans;
    }
};


int main (){

    
    return 0;
}