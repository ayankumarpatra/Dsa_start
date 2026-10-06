#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n= nums.size();

        vector<bool> seen(n+1,false);

        for (int num : nums){
            if (num>0 && num<=n){
                seen[num]=true;
            }
        }

        for (int i=1;i<seen.size();i++){
            if (seen[i]==false){
                return i;
            }
        }

        return n+1;
    }
};



int main (){

    
    return 0;
}