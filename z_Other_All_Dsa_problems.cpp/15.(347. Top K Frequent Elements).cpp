#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;

        for (auto currval:nums){
            um[currval]++;
        }

        priority_queue <pair<int,int>> pq;

        for (auto const& pairs : um){
            pq.push({pairs.second,pairs.first});
        }

        vector<int> returnvect;

        for (int i=0;i<k && !pq.empty() ;++i){
            returnvect.push_back(pq.top().second);
            pq.pop();
        }

        return returnvect;
    }
};


int main (){

    
    return 0;
}