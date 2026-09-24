#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    int get_sum(int x){
        int sum=0;

        while (x>0){
            sum+=x%10;
            x/=10;
        }

        return sum;
    }

    int smallestIndex(vector<int>& nums) {

        for (int i=0;i<nums.size();i++){
            if (nums[i]<10){
                if (nums[i]==i){
                    return nums[i];
                }
            }

            else{
                int temp=get_sum(nums[i]);
                if (temp==i){
                    return temp;
                }
            }
        }

        return -1;
    }
};



int main (){

    
    return 0;
}