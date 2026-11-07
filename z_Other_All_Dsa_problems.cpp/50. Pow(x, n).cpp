#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    double myPow(double x, int n) {
        bool getneg = false;

        if (n<0){
            getneg = true;
            n*= (-1);
        }

        double ret=1;

        while (n>0)
        {
            ret*= x;
            n--;
        }

        if (getneg){
            return 1/ret;
        }

        return ret;
        
    }
};


int main (){

    
    return 0;
}