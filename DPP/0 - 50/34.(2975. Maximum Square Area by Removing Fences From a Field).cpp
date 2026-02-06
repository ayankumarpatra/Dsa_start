#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;


class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        // 1. Add the boundary fences
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        
        // find all possible horizontal gaps
        unordered_set<int> hGaps;
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hGaps.insert(abs(hFences[i] - hFences[j]));
            }
        }
        
        long long maxside = -1;
        
        // find all possible vertical gaps and see if they exist in hgaps
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int gap = abs(vFences[i] - vFences[j]);
                if (hGaps.count(gap)) {
                    maxside = max(maxside, (long long)gap);
                }
            }
        }
        
        // return area or -1
        if (maxside == -1) return -1;
        
        long long MOD = 1e9 + 7;
        return (maxside * maxside) % MOD;
    }
};



int main (){

    
    return 0;
}