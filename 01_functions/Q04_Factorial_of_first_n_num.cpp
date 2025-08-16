#include<iostream>
using namespace std ;
int factorial_value(int n){
    if (n==0 || n==1)
        return 1;
    return n*factorial_value(n-1);// ignoed edge cases as we know we will bw passing first n natural numbers from 0
}
int main (){
int num;
cout<<"Enter the number ";
cin>>num;
if (num<0)
    cout<<"Invalid input"<<endl;
else {
for (int i=0;i<=num;i++)
    cout<<i<<" : "<<factorial_value(i)<<endl;
}
    return 0;
}