#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    // keep INF large enough to avoid overflow when summing costs
    static const long long INF = (long long)1e15;

    long long minimumCost(string source, string target,
                          vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int alpha = 26;
        // 1) building initial cost matrix  cost_mat[u][v] = direct cost u->v or INF if not given
        vector<vector<long long>> cost_mat(alpha, vector<long long>(alpha, INF));

        // convert a letter to index: 'a'->0, 'b'->1, ...
        auto idx = [&](char ch){ return ch - 'a'; };

        // zero cost to convert a letter to itself
        for (int i = 0; i < alpha; ++i) cost_mat[i][i] = 0;

        // fill direct conversion costs from input lists
        for (size_t i = 0; i < original.size(); ++i) {
            int u = idx(original[i]);
            int v = idx(changed[i]);
            long long w = cost[i];
            if (w < cost_mat[u][v]) cost_mat[u][v] = w; // keep minimum if duplicates exist
        }

        // 2) run Floyd–Warshall to compute minimum cost for all pairs (handles indirect paths)
        for (int k = 0; k < alpha; ++k) {
            for (int i = 0; i < alpha; ++i) {
                // small micro-optimization: skip if cost_mat[i][k] is INF
                if (cost_mat[i][k] == INF) continue;
                for (int j = 0; j < alpha; ++j) {
                    if (cost_mat[k][j] == INF) continue;
                    long long alt = cost_mat[i][k] + cost_mat[k][j];
                    if (alt < cost_mat[i][j]) cost_mat[i][j] = alt;
                }
            }
        }

        // 3) sum the minimal cost for each character conversion s[i] -> t[i]
        long long total = 0;
        if (source.size() != target.size()) return -1; // safety, should be same length
        for (size_t i = 0; i < source.size(); ++i) {
            int s = idx(source[i]);
            int t = idx(target[i]);
            if (cost_mat[s][t] >= INF) return -1; // impossible to convert
            total += cost_mat[s][t];
            // optional: if total could exceed some limit, check overflow (not needed here)
        }
        return total;
    }
};



int main (){

    
    return 0;
}