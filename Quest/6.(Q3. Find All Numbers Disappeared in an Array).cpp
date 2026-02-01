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

        returnvector.push_back(1);

        for(int i=0;i<maxlen;i++){
            
        }

        return returnvector;
    }
};


int main (){

    
    return 0;
}