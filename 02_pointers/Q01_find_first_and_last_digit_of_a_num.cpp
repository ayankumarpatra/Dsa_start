#include<iostream>
using namespace std ;
void First_And_Last_Digit(int *first ,int*last ,int n){
    *last=n%10;
    while(n>0){
        *first=n%10;
        n/=10;
    }
}
int main (){
    int num,FirstDig,LastDig;
    cout<<"Enter the number ";
    cin>>num;
    First_And_Last_Digit(&FirstDig,&LastDig,num);
    cout<<"First digit is : "<<FirstDig<<"\nLast digit is : "<<LastDig<<endl;
    return 0;
}