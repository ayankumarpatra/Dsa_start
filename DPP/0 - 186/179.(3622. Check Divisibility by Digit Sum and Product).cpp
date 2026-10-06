#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    bool checkDivisibility(int n) {
        int digit_sum=0,digit_Product=1;

        int mainNum=n;

        while (n>0)
        {
            int currnum=n%10;
                digit_sum+=currnum;
                digit_Product*=currnum;
            n/=10;
        }

        if (digit_Product+digit_sum>0 && mainNum%(digit_Product+digit_sum)==0){
            return true;
        }

        return false;
        
    }
};



int main (){

    
    return 0;
}