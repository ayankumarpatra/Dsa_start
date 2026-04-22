#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

void dfs(int src, auto&adj, vector<int> &indices, auto &t) {
    if(t[src]) return;
    t[src] = true;
    indices.push_back(src);
    for(const auto next: adj[src]) dfs(next, adj, indices, t);
}
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<vector<int>> adj(n);
        for(const auto x: allowedSwaps) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<bool>t(n, false);
int ans = 0;
        for(int i=0;i<n;i++) {
            if(t[i]) continue;

            vector<int> indices;
            dfs(i, adj, indices, t);

            unordered_map<int, int>m;
            for(int j=0;j<indices.size();j++) {
                m[source[indices[j]]]++;
            }
            for(int j=0;j<indices.size();j++) {
                if(m[target[indices[j]]] > 0) {
                    m[target[indices[j]]]--;
                } else {
                    ans++;
                }
            }
            
        }
        return ans;
    }
};

int main (){

    
    return 0;
}