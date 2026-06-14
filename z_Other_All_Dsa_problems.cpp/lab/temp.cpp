#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    bool checkGoodInteger(int n) {
        int squaresum=0,digitsum=0,currnum;

        while (n>0)
        {
            currnum=n%10;
            n/=10;

            digitsum+=n;
            squaresum+= (n*n);

            if (squaresum-digitsum>=50){
                return true;
            }
        }
        if (squaresum-digitsum>=50){
            return true;
        }

        else{
            return false;
        }
        
    }
};



int main (){

    
    return 0;
}