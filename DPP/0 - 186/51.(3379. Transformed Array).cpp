#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {

            // move nums[i] steps from index i (circular)
            int j = (i + nums[i]) % n;
            // fix negative index
            if(j < 0)
                j += n;

            ans[i] = nums[j];
        }
        return ans;
    }
};


int main (){

    
    return 0;
}