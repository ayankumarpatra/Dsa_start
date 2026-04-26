#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int ans =0;
        for (int mask= 1; mask <(1<<n); ++mask) {
            int sum= 0;
            for (int i =0; i<n;++i) {
                if ((mask >>i) &1) {
                sum += nums[i];
                }
            }
            
            if (sum % 2!= 0) continue;
            
            int start = __builtin_ctz(mask);
            int visited =(1 << start);
            vector<int>q;
            q.push_back(start);
            int head = 0;
            
            while (head < q.size()) {
                int u = q[head++];
                for (int v : adj[u]) {
                    if (((mask >> v) & 1) && !((visited >> v) & 1)) {
                        visited |= (1 << v);
                        q.push_back(v);
                    }
                }
            }
            
            if (visited==mask) {
                ans++;
            }
        }
        
        return ans;
    }
};


int main (){

    
    return 0;
}