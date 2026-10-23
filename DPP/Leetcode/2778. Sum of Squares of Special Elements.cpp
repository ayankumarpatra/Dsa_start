#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;



class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        
        int n= nums.size();

        int sq_sum=0;

        for (int i=0;i<n;i++){
            if (n % (i+1) == 0){
                sq_sum += (nums[i]*nums[i]);
            }
        }

        return sq_sum;

    }
};


int main (){

    
    return 0;
}