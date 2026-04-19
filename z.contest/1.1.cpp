#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> pfm(n);
        pfm[0] = nums[0];
        for (int i = 1; i < n; i++)
            pfm[i] = max(pfm[i-1], nums[i]);
        
        vector<int> sfm(n);
        sfm[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--)
            sfm[i] = min(sfm[i+1], nums[i]);
        
        for (int i = 0; i < n; i++) {
            int temp = pfm[i] - sfm[i];
            if (temp <= k)
                return i;
        }
        
        return -1;
    }
};


int main (){

    return 0;
}