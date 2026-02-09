#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int maxlen=nums.size();

        vector<int> returnvector;

        if (nums[0]!=1){
            int temptrack=1;
            while (temptrack<nums[0]){
                returnvector.push_back(temptrack);
                temptrack +=1;
            }
        }

        for(int i=0;i<maxlen-1;i++){

            if (nums[i]==nums[i+1] || nums[i]+1==nums[i+1]){
                continue;
            }

            else {
                int tracker =nums[i]+1;
                while (nums[i+1]>tracker)
                {
                    returnvector.push_back(tracker);
                    tracker+=1;
                }
            }

        }

        if (nums[maxlen-1]<maxlen){
            int tracker=nums[maxlen-1]+1;
                while (tracker<=maxlen)
                {
                    returnvector.push_back(tracker);
                    tracker+=1;
                }
        }

        return returnvector;
    }
};


int main (){

    
    return 0;
}