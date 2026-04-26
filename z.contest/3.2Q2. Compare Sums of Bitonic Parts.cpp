#include<iostream>
#include<climits>
#include<vector>

using namespace std ;


class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int maxval=INT_MIN,maxidx=0;

        long long tempsum=0;

        long long ascendingsum=0,descendingsum=0;

        for(int i=0;i<nums.size();i++){
            tempsum+=nums[i];
            if (nums[i]>maxval){
                maxval=nums[i];
                maxidx=i;
                ascendingsum=tempsum;
            }
        }

        for (int i=maxidx;i<nums.size();i++){
            descendingsum+=nums[i];
        }

        if (ascendingsum>descendingsum){
            return 0;
        }
        else if (descendingsum>ascendingsum){
            return 1;
        }
        else {
            return -1;
        }
    }
};

int main (){

    
    return 0;
}