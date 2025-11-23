#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

int fibo(int n){
    if(n<=1){
        cout<<"0 "<<endl;
        return n;
    }

    return fibo(n-1)+fibo(n-2);

};

int main (){

    int num;

    cout<<"Enter Number of terms you wish to print : ";
    cin>>num;

    cout<<fibo(num);

    return 0;
}