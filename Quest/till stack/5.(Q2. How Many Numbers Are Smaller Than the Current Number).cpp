#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        vector<int> returnvect;
        int maxlen=nums.size();

        for(int i=0;i<maxlen;i++){
            int tempgreater=0;
            for (int j=0;j<maxlen;j++){
                if (nums[j]<nums[i]){
                    tempgreater++;
                }
            }
            returnvect.push_back(tempgreater);
        }

        return returnvect;
    }
};

int main (){

    
    return 0;
}