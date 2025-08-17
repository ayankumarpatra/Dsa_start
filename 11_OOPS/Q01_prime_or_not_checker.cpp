#include<iostream>
#include<cmath>
using namespace std ;
bool prime_checker(int num){
    // while we can run a loop for 2 to n-1 , or n/2 , time complexity will be much higher O(n);
    // so we will run that loop for upto sqrt n , so time taken will be much lower 

    // addded updated v2 1. added edge case for -ve num , 0 also
    // 2. addedd a check if its dividible by 2 3 or 5 ... for more less time 
    // 3. so start the loop from 7 
    if (num==2 || num==3 ||num==5) return true;
    if (num<=1 || num%2==0 || num%3==0 ||num%5==0) return false;
    int temp=sqrt(num);
    for (int i=7;i<=temp;i++){
        if(num%i==0)
            return false;
    }
    return true;
}
int main (){
int num;
cout<<"Enter the number ";
cin>>num;

if (prime_checker(num))
    cout<<num<<" is a prime number ";
else 
    cout<<num<<" is not a prime number ";
    return 0;
}