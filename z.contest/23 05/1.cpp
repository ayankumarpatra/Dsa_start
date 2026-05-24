#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
        int n = parent.size();
        long long MOD = 1e9 + 7;

        vector<vector<long long>> dp0(n,vector<long long>(k,0));
        vector<vector<long long>> dp1(n,vector<long long>(k,0));

        for (int i =0;i <n;++i) {
            dp0[i][0] = 1;
            int rem = (nums[i]%k+k) % k;
            dp1[i][rem]=1;
        }

        for (int sub= n-1; sub> 0;--sub) {
            int p = parent[sub];

            vector<long long> next_p0(k,0);
            vector<long long> next_p1(k,0);

            vector<long long> child_ways(k, 0);
            for (int r = 0; r<k; ++r) {
                child_ways[r]= (dp0[sub][r]+dp1[sub][r]) % MOD;
            }

            for (int r1 = 0; r1<k; ++r1) {
                if (dp0[p][r1]==0 && dp1[p][r1]==0) continue;

                for (int r2 = 0; r2 < k; ++r2) {
                    if (child_ways[r2]==0 && dp0[sub][r2] ==0) continue;

                    int r_next = r1 + r2;
                    if (r_next>=k) r_next -= k;

                    if (dp0[p][r1] > 0 && child_ways[r2] > 0) {
                        next_p0[r_next] =(next_p0[r_next]+dp0[p][r1] * child_ways[r2]) %MOD;
                    }
                    if (dp1[p][r1] > 0 && dp0[sub][r2] > 0) {
                        next_p1[r_next] = (next_p1[r_next] + dp1[p][r1] * dp0[sub][r2]) % MOD;
                    }
                }
            }

            dp0[p] = move(next_p0);
            dp1[p] = move(next_p1);

            dp0[sub].clear();
            dp0[sub].shrink_to_fit();
            dp1[sub].clear();
            dp1[sub].shrink_to_fit();
        }

        long long ans=(dp0[0][0] +dp1[0][0] - 1+MOD)% MOD;
        return ans;
    }
};


int main (){

    
    return 0;
}