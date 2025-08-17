#include<iostream>
#include<cmath>
using namespace std ;
bool prime_checker(int num){
    // while we can run a loop for 2 to n-1 , or n/2 , time complexity will be much higher O(n);
    // so we will run that loop for upto sqrt n , so time taken will be much lower 
    if (num==1) return false;
    for (int i=2;i<=sqrt(num);i++){
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