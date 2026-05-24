#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int countzero=0,operations=0;

        for (int i=0;i<nums.size();i++){
            if (nums[i]==0){
                countzero++;
            }
        }

        for (int i=nums.size()-1;i>=0;i--){
            if (countzero==0){
                break;
            }
            if (nums[i]!=0){
                operations++;
                countzero--;
            }
            else{
                countzero--;
            }
        }
        return operations;
    }
};



int main (){

    
    return 0;
}