#include<iostream>
#include<stack>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:

    int minElement(vector<int>& nums) {
        int minval=INT_MAX;

        for (int currnum:nums){
            int currsum=0;
            while (currnum>0)
            {
                currsum+=(currnum%10);
                currnum/=10;
            }
            if (currsum<minval){
                minval=currsum;
            }
        }
        return minval;
    }
};


int main (){

    
    return 0;
}