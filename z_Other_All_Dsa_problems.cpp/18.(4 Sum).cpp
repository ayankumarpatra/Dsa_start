#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort (nums.begin(),nums.end());

        vector<vector<int>> returnvect;

        int n=nums.size(),next,low,high,sum;

        for (int i=0;i<n;i++){

            if (i>0 && nums[i]==nums[i-1]){continue;}
            
            for (next=i+1;next<n;next++ ){
                if (next>i+1 && nums[next]==nums[next-1]) {continue;}
            low=next+1;
            high=n-1;

            while (low<high)
            {
                sum=nums[i]+nums[next]+nums[low]+nums[high];

                if (sum==target){
                    returnvect.push_back( {nums[i],nums[next],nums[low],nums[high]} );
                    low++;
                    high--;

                    while (low<high && nums[low]==nums[low-1])
                    {
                        low++;
                    }
                    
                }
                else if (sum<target){low++;}
                else {high--;}

            }

        }
        
        }

        return returnvect;
    }
};


int main (){

    
    return 0;
}