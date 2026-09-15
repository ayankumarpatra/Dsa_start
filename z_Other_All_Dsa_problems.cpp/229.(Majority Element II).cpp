#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std ;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map < int, int> um; // key , val pair

        for (int i=0;i<nums.size();i++){
            um[nums[i]]++;
        }

        int n=nums.size()/3;

        vector<int> returnvect;

        for (auto currpair:um){
            if (currpair.second>=n){
                returnvect.push_back(currpair.first);
            }
        }

        return returnvect;
    }
};


int main (){

    
    return 0;
}