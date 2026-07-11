#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        vector<long long> values(nums.begin(), nums.end());
        
        vector<bool> isremoved(n, false);
        
        priority_queue<pair<long long, int>, 
                      vector<pair<long long, int>>, 
                      greater<>> minheap;
        
        int sortedpairs = 0;
        
        for (int i = 1; i < n; i++) {
            minheap.push({values[i-1] + values[i], i-1});
            if (values[i] >= values[i-1]) {
                sortedpairs++;
            }
        }
        
        if (sortedpairs == n - 1) return 0;
        
        int remainingelements = n;
        
        vector<int> leftn(n), rightn(n);
        for (int i = 0; i < n; i++) {
            leftn[i] = i - 1;
            rightn[i] = i + 1;     
        }
        

        while (remainingelements > 1) {

            auto [pairsum, leftid] = minheap.top();
            minheap.pop();
            
            int rightIdx = rightn[leftid];
            
            if (rightIdx >= n || isremoved[leftid] || isremoved[rightIdx] ||
                values[leftid] + values[rightIdx] != pairsum) {
                continue;
            }
            
            int leftOfPair = leftn[leftid];
            int rightOfPair = rightn[rightIdx];
            
            if (values[leftid] <= values[rightIdx]) {
                sortedpairs--;
            }

            if (leftOfPair != -1 && values[leftOfPair] <= values[leftid]) {
                sortedpairs--;
            }

            if (rightOfPair != n && values[rightIdx] <= values[rightOfPair]) {
                sortedpairs--;
            }
            
            values[leftid] += values[rightIdx];
            isremoved[rightIdx] = true;
            remainingelements--;

            if (leftOfPair == -1) {
                leftn[leftid] = -1;  
            } else {
                minheap.push({values[leftOfPair] + values[leftid], leftOfPair});

                if (values[leftOfPair] <= values[leftid]) {
                    sortedpairs++;
                }
            }
            
            if (rightOfPair == n) {
                rightn[leftid] = n; 
            } else {
                leftn[rightOfPair] = leftid;
                rightn[leftid] = rightOfPair;
                minheap.push({values[leftid] + values[rightOfPair], leftid});
                if (values[leftid] <= values[rightOfPair]) {
                    sortedpairs++;
                }
            }
            
            if (sortedpairs == remainingelements - 1) {
                return n - remainingelements; 
            }
        }
        
        return n - remainingelements;
    }
};


long long main (){

    
    return 0;
}