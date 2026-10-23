#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> dist(nums.size(),0);

        for (int i=0;i<nums.size();i++){
            long long tempval=0;
            for (int j=0;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    if (i==j){
                        continue;
                    }
                    tempval+=abs(i-j);
                }        
            }
            dist[i]=tempval;
        }
        return dist;
    }
};

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n);
        unordered_map<long long,vector<int>> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        
        for(auto &idx:mp){
            auto &arr = idx.second;
            int siz = arr.size();

            vector<long long> pref(siz,0);
            pref[0] = arr[0];

            for(int i=1;i<siz;i++){
                pref[i] = pref[i-1] + arr[i];
            }

            for(int i=0;i<siz;i++){
                long long left = 0, right = 0;

                if(i > 0){
                    left = (long long)i * arr[i] - pref[i-1];
                }
                if(i < siz-1){
                    right = (pref[siz-1] - pref[i]) - (long long)(siz-i-1) * arr[i];
                }
                res[arr[i]] = left + right;
            }
        }
        return res;
    }
};

int main (){

    
    return 0;
}