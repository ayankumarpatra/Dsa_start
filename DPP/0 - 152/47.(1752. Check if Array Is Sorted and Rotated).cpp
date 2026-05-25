#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    bool check(vector<int>& nums) {

        for (int i=0;i<nums.size()-1;i++){
            if (nums[i]<nums[i+1]){
                int nextidx,previdx;
                if (i+1<nums.size()-1){ nextidx=i+1;}
                else{ nextidx=0; }

                if (i-1>0){previdx=i-1;}
                else {previdx=nums.size()-1;}
                
            if (nums[previdx]<nums[nextidx]){
                return false;
            }
        }
    }
        return true;
    }
};

int main (){

    
    return 0;
}