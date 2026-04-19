#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans=nums;
        
        nums.reserve(nums.size()+nums.size());

        nums.insert(nums.end(),nums.begin(),nums.end());

        return nums;
    }
};

int main (){

    
    return 0;
}