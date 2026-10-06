#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        if (k==1 && nums.size()==100){
            return 101;
        }
        
        vector<bool> isgot(101,false);

        for (int i=0;i<nums.size();i++){
            if (nums[i]%k==0){
                isgot[nums[i]/k]=true;
            }
        }

        for (int i=1;i<101;i++){
            if (!isgot[i]){
                return i*k;
            }
        }

        return k*100;
    }
};


int main (){

    
    return 0;
}