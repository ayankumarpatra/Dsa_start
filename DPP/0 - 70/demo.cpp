#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {

        int total_diffs = 0;
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = (start[i] != target[i]);
            if (diff[i]) total_diffs++;
        }

        if (total_diffs % 2 != 0) {
            return {-1};
        }

        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            adj[edges[i][0]].push_back({edges[i][1], i});
            adj[edges[i][1]].push_back({edges[i][0], i});
        }

        vector<int> result;

        vector<int> needtoflip = diff;
        
        vector<int> parent(n, -1);
        vector<int> mainedgeindex(n, -1);
        vector<int> order;
        vector<int> stack = {0};
        vector<bool> visited(n, false);
        visited[0] = true;

        int head = 0;
        vector<int> q = {0};
        while(head < q.size()){
            int u = q[head++];
            order.push_back(u);
            for(auto& edge : adj[u]){
                int v = edge.first;
                int idx = edge.second;
                if(!visited[v]){
                    visited[v] = true;
                    parent[v] = u;
                    mainedgeindex[v] = idx;
                    q.push_back(v);
                }
            }
        }

        for (int i = n - 1; i > 0; --i) {
            int u = order[i];

            if (needtoflip[u]) {
                result.push_back(mainedgeindex[u]);

                needtoflip[u] = 0;
                needtoflip[parent[u]] = !needtoflip[parent[u]];
            }
        }


        if (needtoflip[order[0]]) {
            return {-1};
        }

        sort(result.begin(), result.end());
        return result;
    }
};