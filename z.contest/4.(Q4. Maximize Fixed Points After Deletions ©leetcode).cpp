#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

#include <vector>
#include <algorithm>

using namespace std;

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> candidates;

        for (int i = 0; i<n; ++i) {
            if (nums[i] <= i && nums[i]>=0) {
                candidates.push_back({i-nums[i],nums[i]});
            }
        }

        sort(candidates.begin(), candidates.end(),[](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first != b.first) {
                return a.first<b.first;
            }
            return a.second <b.second;
        });

        vector<int> tails;
        for (const auto& p : candidates) {
            int val = p.second;
            auto it = lower_bound(tails.begin(), tails.end(), val);
            
            if (it == tails.end()) {
                tails.push_back(val);
            } else {
                *it = val;
            }
            }

        return tails.size();
    }
};

int main (){

    
    return 0;
}