#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vals = nums;
        sort(vals.begin(),vals.end());
        vals.erase(unique(vals.begin(),vals.end()), vals.end());
        int m =vals.size();
        
        const long long MIN_VAL= -1000000000000000000LL;
        vector<long long>bit_down(m + 1, MIN_VAL);
        vector<long long>bit_up(m + 1, MIN_VAL);
        
        auto update_down = [&](int idx, long long val) {
            for (idx <= m; idx += idx & -idx) {
                bit_down[idx] = max(bit_down[idx], val);
            }
        };
        
        auto query_down = [&](int idx) {
            long long res = MIN_VAL;
            for (; idx > 0; idx -= idx & -idx) {
                res = max(res, bit_down[idx]);
            }
            return res;
        };
        
        auto update_up = [&](int idx, long long val) {
            for (; idx <= m; idx += idx & -idx) {
                bit_up[idx] = max(bit_up[idx], val);
            }
        };
        
        auto query_up = [&](int idx) {
            long long res = MIN_VAL;
            for (;idx > 0; idx -= idx & -idx) {
                res =max(res, bit_up[idx]);
            }
            return res;
        };
        
        vector<long long>dpUp(n), dpDown(n);
        long long ans = MIN_VAL;
        int gap =max(1, k);
        
        for (int i = 0; i < n; ++i) {
            if (i >= gap) {
                int prev = nums[i - gap];
                int r = lower_bound(vals.begin(), vals.end(), prev)-vals.begin() + 1;
                update_down(r,dpDown[i - gap]);
                update_up(m - r + 1, dpUp[i - gap]);
            }
            
            long long x = nums[i];
            int rank = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
            
            long long max_d = query_down(rank - 1);
            dpUp[i] = x;
            if (max_d != MIN_VAL) {
                dpUp[i] = max(dpUp[i], x + max_d);
            }
            
            long long max_u = query_up(m - rank);
            dpDown[i] = x;
            if (max_u != MIN_VAL) {
                dpDown[i] = max(dpDown[i], x + max_u);
            }
            
            ans = max({ans, dpUp[i], dpDown[i]});
        }
        
        return ans;
    }
};


int main (){

    
    return 0;
}