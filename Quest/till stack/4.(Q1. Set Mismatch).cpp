#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int maxlen=nums.size();
        vector<int> returnvect;

        sort(nums.begin(),nums.end());
        int start=1;

        for (int i=0;i<maxlen-1;i++){
            if (nums[i]==start){
                start++;
            }
            if (nums[i]==nums[i+1]){

                for (int j=i;j<maxlen;j++){
                    if(nums[j]==start){
                        start++;
                    }
                }


                returnvect.push_back(nums[i]);
                returnvect.push_back(start);
                break;
            }
        }

        return returnvect;
    }
};


int main (){

    
    return 0;
}