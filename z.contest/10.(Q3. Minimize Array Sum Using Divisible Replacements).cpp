#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;


class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        vector<bool> isvisited(nums.size(),false);

        int sum=0;

        for (int i=0;i<nums.size();i++){
            int temp=nums[i];

            for (int j=nums.size()-1;j>i;j--){
                if(nums[j]%temp==0 && isvisited[j]==false){
                    nums[j]=temp;// see first time visit mereturnvect its the smallest element only
                    isvisited[j]=true;
                }
            }
            sum+=nums[i];
        }

        return sum;
    }
};





int main (){

    
    return 0;
}