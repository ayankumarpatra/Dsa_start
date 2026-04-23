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



int main (){

    
    return 0;
}