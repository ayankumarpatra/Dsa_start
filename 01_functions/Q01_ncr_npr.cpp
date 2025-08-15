#include<iostream>
using namespace std ;
    int factorial_value (int n){
        if (n<0){
            cout<<"Negetive numbers cant have factorial value.Error!\n";
            return 0;
        }
        if (n==0 or n==1)
            return 1;
        return n*factorial_value(n-1);
                }

    int ncr_value (int n , int r){
        if (n>0 && r>=0 && n>=r) {
            return factorial_value(n) /(factorial_value(r) *factorial_value(n-r));
        } 
        else cout<<"Sorry ! cant calculate ncr value for the given values \n";
        return 0;
    }

    int npr_value(int n , int r ){
    if (n>0 && r>=0 && n>=r) 
        return factorial_value(n)/factorial_value(n-r);
    else { cout<<"Sorry ! cant calculate npr value for the given values \n";
        return 0;
    }
    }
int main (){

int num ,r;
cout<<"Enter the total number of items (n): ";
cin>>num;
cout<<"Enter the number of items to choose (r): ";
cin>>r;
//cout<<"Factorial value is : "<<factorial_value(num);
cout<<"ncr value is : "<<ncr_value(num,r)<<endl;
cout<<"npr value is : "<<npr_value(num,r)<<endl;
    return 0;
}