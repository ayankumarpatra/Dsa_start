#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int maxlen=nums.size();
        vector<int> returnvector;

        int sum=0;

        for (int i=0;i<maxlen;i++){
            sum+=nums[i];
            returnvector.push_back(i);

            if (sum==target){
                return returnvector;
            }
        }

        return returnvector;
    }
};


int main (){

    
    return 0;
}