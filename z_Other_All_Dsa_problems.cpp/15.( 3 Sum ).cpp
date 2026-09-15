#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort (nums.begin(),nums.end());
        
        vector<vector<int>> returnvect;

        int n=nums.size(),j,k,sum;

        for (int i=0;i<n;i++){
            /* optimization 1 
                if both start point same , remaining rsults will be same also 
            */

            if (i>0 && nums[i]==nums[i-1]){ continue; }

            j=i+1;
            k=n-1;

            while (j<k)
            {
                sum = nums[i]+nums[j]+nums[k];

                if (sum == 0){
                    returnvect.push_back({ nums[i],nums[j],nums[k]});

                    j++;
                    k--;
                    // optimization 2
                    /*  if the mid j value same  eg 0 0 0  for each j =0 , we get the remaining 
                        pairs also same as i same , j same , k will be also same 
                    */
    
                    while (j<k && nums[j]==nums[j-1])
                    {
                        j++;
                    }

                }

                else if (sum>0){k--;}// as k is the largest element 
                else {j++;}// as j is the smallest element 

                
            }
            
        }

        return returnvect;
    }
};



int main (){

    
    return 0;
}