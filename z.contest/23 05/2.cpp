#include<iostream>
#include<climits>
#include<vector>

using namespace std ;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {  
        int n = nums.size();
        vector<int> even_freq(k, 0);
        vector<int> odd_freq(k, 0);

        for (int i = 0; i < n; ++i) {
            int rem = (nums[i] % k + k) % k;
            if (i % 2 == 0) {
                even_freq[rem]++;
            } else {
                odd_freq[rem]++;
            }
        }

        vector<long long> even_cost(k, 0);
        vector<long long> odd_cost(k, 0);

        for (int target = 0; target < k; ++target) {
            for (int rem = 0; rem < k; ++rem) {
                int dist = min(abs(rem - target), k - abs(rem - target));
                even_cost[target] += (long long)even_freq[rem] * dist;
                odd_cost[target] += (long long)odd_freq[rem] * dist;
            }
        }

        auto get_top_two = [&](const vector<long long>& cost) {
            int min1 = -1, min2 = -1;
            for (int i = 0; i < k; ++i) {
                if (min1 == -1 || cost[i] < cost[min1]) {
                    min2 = min1;
                    min1 = i;
                } else if (min2 == -1 || cost[i] < cost[min2]) {
                    min2 = i;
                }
            }
            return make_pair(min1, min2);
        };

        auto [even1, even2] = get_top_two(even_cost);
        auto [odd1, odd2] = get_top_two(odd_cost);

        long long min_ops = LLONG_MAX;
        int even_choices[] = {even1, even2};
        int odd_choices[] = {odd1, odd2};

        for (int x : even_choices) {
            if (x == -1) continue;
            for (int y : odd_choices) {
                if (y == -1) continue;
                if (x != y) {
                    min_ops = min(min_ops, even_cost[x] + odd_cost[y]);
                }
            }
        }

        return min_ops;
    }
};


int main (){

    
    return 0;
}