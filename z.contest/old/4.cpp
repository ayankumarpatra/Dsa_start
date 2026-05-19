#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n =nums.size();
        long long ans= 0;
        for (int r= 0; r<n; r++) {
            int curror = 0, currmax = 0;
            for (int l = r; l >= 0; l--) {
                curror |= nums[l];
                currmax = max(currmax, nums[l]);
                if (curror == currmax) ans++;
            }
        }
        return ans;
    }
};
// got Tle Up soln

class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();

        int LOG = __lg(n) + 2;
        vector<vector<int>> sp(LOG, vector<int>(n));
        sp[0] = nums;
        for (int j = 1; j < LOG; j++)
            for (int i = 0; i + (1<<j) <= n; i++)
                sp[j][i] = max(sp[j-1][i], sp[j-1][i+(1<<(j-1))]);

        auto qmax = [&](int l, int r) {
            int k = __lg(r - l + 1);
            return max(sp[k][l], sp[k][r-(1<<k)+1]);
        };

        long long ans = 0;
        vector<pair<int,int>> or_segs;

        for (int r = 0; r < n; r++) {
            vector<pair<int,int>> new_segs;
            new_segs.push_back({nums[r], r});
            for (auto& [orv, idx] : or_segs) {
                int merged = orv | nums[r];
                if (merged != new_segs.back().first)
                    new_segs.push_back({merged, idx});
                else
                    new_segs.back().second = idx; // extend leftmost
            }
            or_segs = new_segs;

            for (int i = 0; i < (int)or_segs.size(); i++) {
                int orval  = or_segs[i].first;
                int low_bound = or_segs[i].second;
                int r_bound = (i == 0) ? r : or_segs[i-1].second - 1;

                if (qmax(low_bound, r) != orval) continue;

                int lo = low_bound, hi = r_bound, boundary = low_bound - 1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (qmax(mid, r) == orval) {
                        boundary = mid;
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
                ans += (boundary - low_bound + 1);
            }
        }
        return ans;
    }
};


int main (){

    
    return 0;
}