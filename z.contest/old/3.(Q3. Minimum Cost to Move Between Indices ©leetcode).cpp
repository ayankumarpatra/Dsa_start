#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<long long> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> pref_right(n, 0);
        vector<long long> pref_left(n, 0);

        for (int i = 0; i < n - 1; ++i) {
            long long cost;
            if (i == 0) {
                cost = 1;
            } else {
                long long diff_left = (long long)nums[i] - nums[i - 1];
                long long diff_right = (long long)nums[i + 1] - nums[i];
                cost = (diff_right < diff_left) ? 1 : diff_right;
            }
            pref_right[i + 1] = pref_right[i] + cost;
        }

        for (int i = n - 1; i > 0; --i) {
            long long cost;
            if (i == n - 1) {
                cost = 1;
            } else {
                long long diff_left = (long long)nums[i] - nums[i - 1];
                long long diff_right = (long long)nums[i + 1] - nums[i];
                cost = (diff_left <= diff_right) ? 1 : diff_left;
            }
            pref_left[i - 1] = pref_left[i] + cost;
        }

        vector<long long> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            if (l <= r) {
                ans.push_back(pref_right[r] - pref_right[l]);
            } else {
                ans.push_back(pref_left[r] - pref_left[l]);
            }
        }
        return ans;
    }
};


int main (){

    
    return 0;
}