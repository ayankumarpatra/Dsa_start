#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


#include <bits/stdc++.h>
using namespace std;

// disjoint set union (union find)
class dsu {
public:
    vector<int> parent;
    vector<int> rank_val;

    // initialize dsu
    dsu(int n) {
        parent.resize(n);
        rank_val.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // find parent with path compression
    int find_parent(int node) {
        if (parent[node] != node)
            parent[node] = find_parent(parent[node]);
        return parent[node];
    }

    // union two nodes
    bool unite(int a, int b) {

        int parent_a = find_parent(a);
        int parent_b = find_parent(b);

        if (parent_a == parent_b)
            return false;

        // union by rank
        if (rank_val[parent_a] < rank_val[parent_b])
            parent[parent_a] = parent_b;

        else if (rank_val[parent_b] < rank_val[parent_a])
            parent[parent_b] = parent_a;

        else {
            parent[parent_b] = parent_a;
            rank_val[parent_a]++;
        }

        return true;
    }
};

class Solution {
public:

    // check if we can build a spanning tree with minimum stability = target
    bool can_build_tree(int n, vector<vector<int>>& edges, int k, int target) {

        dsu uf(n);
        int edges_used = 0;

        vector<vector<int>> good_edges;      // edges already satisfying stability
        vector<vector<int>> upgrade_edges;   // edges that need upgrade

        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int stability = edge[2];
            int mandatory = edge[3];

            // mandatory edges must be included
            if (mandatory == 1) {

                if (stability < target)
                    return false;

                if (!uf.unite(u, v))
                    return false;

                edges_used++;
            }
            else {

                if (stability >= target)
                    good_edges.push_back(edge);

                else if (2 * stability >= target)
                    upgrade_edges.push_back(edge);
            }
        }

        // first try using edges that already satisfy stability
        for (auto &edge : good_edges) {

            if (uf.unite(edge[0], edge[1])) {

                edges_used++;

                if (edges_used == n - 1)
                    return true;
            }
        }

        // then use upgrade edges if needed
        int upgrades_used = 0;

        for (auto &edge : upgrade_edges) {

            if (upgrades_used == k)
                break;

            if (uf.unite(edge[0], edge[1])) {

                upgrades_used++;
                edges_used++;

                if (edges_used == n - 1)
                    return true;
            }
        }

        return edges_used == n - 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        int max_stability = 0;

        for (auto &edge : edges)
            max_stability = max(max_stability, edge[2]);

        int left = 0;
        int right = 2 * max_stability;
        int answer = -1;

        // binary search on possible stability value
        while (left <= right) {

            int mid = (left + right) / 2;

            if (can_build_tree(n, edges, k, mid)) {
                answer = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return answer;
    }
};

int main (){

    
    return 0;
}