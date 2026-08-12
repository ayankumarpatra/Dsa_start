#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int n= nums.size();
        unordered_map<int,int> freq;

        int count=0;
        freq.reserve(n);// reserve space for faster execution

        for (int left=0,right=0 ; right<n ; right++){
            int temp= nums[right];

            int f=++freq[temp];

            while (freq[temp]>k)
            {
                int leftnum= nums[left];

                freq[leftnum]--;// decreasew the freq of the leftmost el

                left++; // move the window
            }
            
            count = max(count, right -left +1);
        }



    }
};


int main (){

    
    return 0;
}