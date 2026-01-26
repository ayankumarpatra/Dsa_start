#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int travel_value=1;// already said 1 to n

        int maxlen=nums.size();

        vector<int> returnvector;

        for(int i=0;i<maxlen;i++){
            if (nums[i]!=travel_value){
                returnvector.push_back(travel_value);
                travel_value++;
            }
            if (nums[i]==travel_value){
                travel_value++;
            }
        }

        return returnvector;
    }
};


int main (){

    
    return 0;
}