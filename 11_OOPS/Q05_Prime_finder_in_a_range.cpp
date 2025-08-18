// Given an integer n, return the number of prime numbers that are strictly less than n.

#include<iostream>
#include<cmath>
using namespace std ;

bool prime_checker(int num){
    if (num==2 || num==3 ||num==5) return true;
    if (num<=1 || num%2==0 || num%3==0 ||num%5==0) return false;
    int temp=sqrt(num);
    for (int i=7;i<=temp;i++){
        if(num%i==0)
            return false;
    }
    return true;
}

int NumberOfPrimes(int range){
    if(range<=2) return 0;
    int z=range/2,find=1;
    for (int i=1;i<z;i++){
        if (prime_checker(2*i+1))
            find++;
    }
    return find;
}

int main (){
int range;
cout<<"Enter the range ";
cin>>range;

cout<<NumberOfPrimes(range);
    return 0;
}