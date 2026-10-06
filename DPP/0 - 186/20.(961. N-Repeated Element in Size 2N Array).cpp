#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        int n= nums.size();

        for (int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                if (nums[i]==nums[j]){
                    return nums[j];
                }
            }
        }
        
    }
};


int main (){

    
    return 0;
}