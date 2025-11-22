#include<iostream>


using namespace std ;

int facto(int val){
    if(val==0||val==1){
        return 1;
    }

    return val*facto(val-1);
}



int main (){

    int num;

    cout<<"Enter NUmber : ";
    cin>>num;

    cout<<"Factorial value is : "<<facto(num);

    return 0;
}