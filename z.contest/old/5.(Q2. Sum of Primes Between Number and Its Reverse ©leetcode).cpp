#include<iostream>
#include<cmath>
#include<vector>

using namespace std ;

class Solution {
public:
    bool isprime(int num){
        if (num < 2) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        int maxval = sqrt(num);
        for(int i = 3; i <=maxval;i+= 2){
            if (num % i == 0){
                return false;
            }
        }
        return true;
    }

    int sumOfPrimesInRange(int n) {
        int revnum =0, copynum=n;
        
        while(copynum > 0){
            int temp = copynum % 10;
            revnum = (revnum*10) + temp;
            copynum/= 10;
        }

        int primesum = 0;
        for (int i = min(n, revnum);i<= max(n, revnum); i++){
            if (isprime(i)){
                primesum +=i;
            }
        }
        return primesum;
    }
};


int main (){

    
    return 0;
}