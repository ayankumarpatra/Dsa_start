#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> returnvect;

        int basenum=nums[0];

        for (int i=0;i<nums.size();i++){
            if (nums[i]!=basenum){
                    returnvect.push_back(basenum);
                    i--;
            }
            basenum++;
        }
        return returnvect;
    }
};

int main (){

    
    return 0;
}