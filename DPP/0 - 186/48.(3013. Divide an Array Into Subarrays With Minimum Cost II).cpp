#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

/*
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long minCost = LLONG_MAX;
        
        long long firstCost = nums[0];
        
        for (int i = 1; i + dist < n && i < n; i++) {
            vector<int> window;
            for (int j = i; j <= min(i + dist, n - 1); j++) {
                window.push_back(nums[j]);
            }
            sort(window.begin(), window.end());
            long long cost = firstCost;
            for (int p = 0; p < k - 1 && p < window.size(); p++) {
                cost += window[p];
            }
            minCost = min(minCost, cost);
        }
        return minCost;
    }
};

*/

class Solution {
 public:
  long long minimumCost(vector<int>& nums, int k, int dist) {
    long long windowSum = 0;  // sum of elements in selected
    multiset<int> selected, candidates;

    // build initial window [1 .. dist+1]
    for (int i = 1; i <= dist + 1; ++i) {
      selected.insert(nums[i]);
      windowSum += nums[i];
    }

    // now reduce selected so it only has k-1 smallest
    while ((int)selected.size() > k - 1) {
      auto it = prev(selected.end());
      windowSum -= *it;
      candidates.insert(*it);
      selected.erase(it);
    }

    long long ans = windowSum;

    // slide the window
    for (int i = dist + 2; i < nums.size(); ++i) {
      int out = nums[i - dist - 1];
      // remove the outgoing value
      if (selected.find(out) != selected.end()) {
        windowSum -= out;
        selected.erase(selected.find(out));
      } else {
        candidates.erase(candidates.find(out));
      }
      // add the incoming
      if (!selected.empty() && nums[i] < *prev(selected.end())) {
        selected.insert(nums[i]);
        windowSum += nums[i];
      } else {
        candidates.insert(nums[i]);
      }
      // rebalance so selected has k-1 elements
      while ((int)selected.size() < k - 1) {
        auto it = candidates.begin();
        windowSum += *it;
        selected.insert(*it);
        candidates.erase(it);
      }
      while ((int)selected.size() > k - 1) {
        auto it = prev(selected.end());
        windowSum -= *it;
        candidates.insert(*it);
        selected.erase(it);
      }
      ans = min(ans, windowSum);
    }

    return nums[0] + ans;
  }
};


int main (){

    
    return 0;
}