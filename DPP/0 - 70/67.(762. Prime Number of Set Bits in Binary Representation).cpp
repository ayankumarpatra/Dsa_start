#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    bool isprime(int n){
        if (n<=1){
            return false;
        }
        else if (n<=3){
            return 3;
        }
        else if (!(n&1) || (n%3)==0){
            return false;
        }

        for (int i=5;i*i<=n;i+=6){
            if (n%i==0||(n+i)%2==0){
                return false;
            }
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int result=0,bitcount=0,noofbits;

        for (left;left<right;left++){
            noofbits=__builtin_popcount(left);
            
            if (isprime(noofbits)){
                result++;
            }
        }
        return result;
    }
};


int main (){

    
    return 0;
}