#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        for (int i =0; i<n;++i) {
            prefix[i+1] =prefix[i] + (nums[i]%2 == 0 ? 1:0);
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q :queries) {
            int l =q[0], r =q[1], k= q[2];
            long long low =1,high=(long long)k+(r-l+1);
            long long res =high;
            
            while (low <=high) {
                long long mid =low +(high-low)/2;
                long long x = mid*2;
                
                auto it = upper_bound(nums.begin()+l,nums.begin()+r+1, x);
                int c = 0;
                
                if (it >nums.begin()+ l) {
                    int idx = (it - nums.begin()) -1;
                    c = prefix[idx+1] -prefix[l];
                }
                
                if (mid -c>= k) {
                    res =mid;
                    high= mid -1;
                } else {
                    low =mid+1;
                }
            }
            ans.push_back(res*2);
        }
        return ans;
    }
};


int main (){

    
    return 0;
}