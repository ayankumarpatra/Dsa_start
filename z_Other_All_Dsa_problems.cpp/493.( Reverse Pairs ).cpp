#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;



// brute force is good but need to optimize it 
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        /*
    A reverse pair is a pair (i, j) where:

    0 <= i < j < nums.length and
    nums[i] > 2 * nums[j].

        */

        int n= nums.size();

        int count=0;

        for (int i=0;i<n-1;i++ ){
            for (int j=i+1;j<n;j++){
                if (nums[i] > 2 * nums[j]){
                    count++;
                }
            }
        }

        return count;
    }
};

// trying to optimize using merge sort 

class Solution {
public:

    
void counter ( vector<int>& nums , int low , int high , int &count ){

    while (low<high)
    {
        if (nums[low]> 2LL *nums[high] ){
            count++;

            low++;
            high--;
        }
    }
    
    }

    void divider ( vector<int>& nums , int &count ){
        int mid = nums.size()/2;

        counter (nums , 0 , mid , count);
        counter (nums , mid+1, nums.size() , count);
    }

    int reversePairs(vector<int>& nums) {
        int count=0;

        divider(nums,count);

        return count;
    }
};



int main (){

    
    return 0;
}