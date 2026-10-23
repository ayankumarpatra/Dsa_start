#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        if (nums.size()<2){
            return false;
        }

        if (nums[nums.size()-1]!=nums[nums.size()-2]){
            return false;
        }

        for (int i=1;i<=nums.size();i++){
            if (nums[i-1]!=i){
                return false;
            }
        }
        return true;
    }
};

int main (){
    return 0;

    
    return 0;
}