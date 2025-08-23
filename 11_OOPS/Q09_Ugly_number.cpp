//An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.

#include<iostream>
#include<cmath>
using namespace std ;

    bool isUgly(int num) {
        if (num<=0) return 0;
        while (num%2==0) num/=2;
        while (num%3==0) num/=3;
        while (num%5==0) num/=5;

        return (num==1);
    }

int main (){

    cout<<isUgly(9);
    return 0;
}

/*
base logic , i self made so keep it ;
    bool isprime (int num){
        if (num<2){
            return 0;
        }
        if(num==2){
            return 1;
        }
        if (num%2==0){
            return 0;
        }
        for (int i=3;i<sqrt(num);i+=2){
            if(num%2==0){
                return 0;
            }
        }
        return 1;
    }

    bool isUgly(int num) {
        if (num<1) return 0;
        if (num==1 || num==2) return 1;
        if (num>5 && isprime(num)) return 0;
        int flagfactor=0;
        if (num%2==0 || num%3==0 || num%5==0){
            flagfactor=1;
        }
        else return 0;

        if (flagfactor){
        for (int i=3;i<=(num/2);i+=2){
            if(num%i==0 & isprime (i) && i>5){
                    return 0;
            }
        }
    }
        return 1*flagfactor;
    }

*/