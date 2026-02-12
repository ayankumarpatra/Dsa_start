#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    int tree_min[400005], tree_max[400005], lazy[400005];

    void push(int node) {
        if (lazy[node] != 0) {
            tree_min[2 * node] += lazy[node];
            tree_max[2 * node] += lazy[node];
            lazy[2 * node] += lazy[node];
            
            tree_min[2 * node + 1] += lazy[node];
            tree_max[2 * node + 1] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
            
            lazy[node] = 0;
        }
    }

    // Update a range [l, r] with a value v
    void update(int node, int start, int end, int l, int r, int v) {
        if (start > end || start > r || end < l) return;
        if (start >= l && end <= r) {
            tree_min[node] += v;
            tree_max[node] += v;
            lazy[node] += v;
            return;
        }
        push(node);
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, v);
        update(2 * node + 1, mid + 1, end, l, r, v);
        tree_min[node] = min(tree_min[2 * node], tree_min[2 * node + 1]);
        tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
    }

    int find_rightmost(int node, int start, int end, int l, int r) {
        if (start > end || start > r || end < l || tree_min[node] > 0 || tree_max[node] < 0) {
            return -1;
        }
        if (start == end) return start;
        push(node);
        int mid = (start + end) / 2;

        int res = find_rightmost(2 * node + 1, mid + 1, end, l, r);
        if (res == -1) {
            res = find_rightmost(2 * node, start, mid, l, r);
        }
        return res;
    }

public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<=4*n; i++) tree_min[i] = tree_max[i] = lazy[i] = 0;

        unordered_map<int, int> first_occ;
        int max_len = 0;

        // Iterate backwards: l is the start of the subarray
        for (int l = n - 1; l >= 0; --l) {
            int val = (nums[l] % 2 == 0) ? 1 : -1;

            if (first_occ.count(nums[l])) {
                update(1, 0, n - 1, first_occ[nums[l]], n - 1, -val);
            }

            first_occ[nums[l]] = l;
            update(1, 0, n - 1, l, n - 1, val);

            int r = find_rightmost(1, 0, n - 1, l, n - 1);
            if (r != -1) {
                max_len = max(max_len, r - l + 1);
            }
        }
        return max_len;
    }
};

int main (){

    
    return 0;
}