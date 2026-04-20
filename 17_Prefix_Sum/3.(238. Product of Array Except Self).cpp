#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mainprod=1;
        vector<int> zeroidx;

        bool iszero=false,allzero=true;

        for (int i=0;i<nums.size();i++){
            if (nums[i]!=0){
                mainprod*=nums[i];
                allzero=false;
            }
            else {
                iszero=true;
                zeroidx.push_back(i);
            }
        }

        vector<int> productvect(nums.size(),0);

        if (allzero){
            return productvect;
        }

        if (!iszero){
                for (int i=0;i< nums.size();i++){
            if (nums[i]!=0){
                productvect[i]=mainprod/nums[i];
            }
        }
        }

        else {
            for (int i=0;i< zeroidx.size();i++){
                productvect[zeroidx[i]]=mainprod;
            }
        }

        return productvect;
    }
};



int main (){

    
    return 0;
}