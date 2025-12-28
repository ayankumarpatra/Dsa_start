#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        sort(happiness.rbegin(),happiness.rend());

        int count=happiness[0];

        for (int i=1;i<=k;i++){
            if (happiness[i]<=0 || k==1){
                break;
            }

            count+=happiness[i]-1;
        }


        return count;
    }
};


int main (){

    
    return 0;
}