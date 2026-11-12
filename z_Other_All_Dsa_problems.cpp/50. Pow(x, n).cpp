#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    double getpow_val ( double x , long long int n){
        if ( n==0 ){
            return 1;
        }

        double temp = getpow_val(x, n/2);

        if ( n%2 == 0 ){
            return temp*temp;
        }

        else {
            return x*temp*temp;
        }
    }

    double myPow(double x, int n) {

    if (n<0){
        return 1 / getpow_val(x , (long long)n );
    }


    return getpow_val(x , (long long)n );
        
    }
};


int main (){

    
    return 0;
}