#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> um;// its actually the value , index pair

        vector<int> returnvect;

        for (int i=0;i<nums.size();i++){
            int remaining=target-nums[i];

            if(um.find(remaining)!=um.end()){
                returnvect.push_back(i);
                returnvect.push_back(um.find(remaining)->second);
                return returnvect;
            }

            um[nums[i]]=i;
        }
        return returnvect;
    }
};


int main (){

    
    return 0;
}