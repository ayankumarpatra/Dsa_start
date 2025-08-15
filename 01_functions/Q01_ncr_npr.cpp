#include<iostream>
using namespace std ;
    int factorialvalue (int n){
        if (n<0){
            cout<<"Negetive numbers cant have factorial value.Error! ";
            return 0;
        }
        if (n==0 or n==1)
            return 1;
        return n*factorialvalue(n-1);
                }

    int ncr_value (int n , int r){
        if (n>0 && r>=0 && n>=r) {
            return factorialvalue(n) /(factorialvalue(r) *factorialvalue(n-r));
        } 
        else cout<<"Sorry ! cant claculate ncr value for the given values \n";
        return -1;
    }
int main (){
/*
git add .
git commit -m "Added Functions folder with initial codes"
git push

ncr = n! /r! * n-r!
*/
int num ,r;
cout<<"Enter the total number of items (n): ";
cin>>num;
cout<<"Enter the number of items to choose (r): ";
cin>>r;
//cout<<"Factorial value is : "<<factorialvalue(num);
cout<<"ncr value is : "<<ncr_value(num,r);

//cout<<"Factorial value is : "<<factorialvalue(num);

    return 0;
}