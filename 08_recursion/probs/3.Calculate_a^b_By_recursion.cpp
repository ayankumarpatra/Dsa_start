// calculate a^b and return value 

#include<iostream>

using namespace std ;


int calculate_Power(int num,int power){

    if(power==0){
        return 1;
    }

    return num*calculate_Power(num,power-1);
}

int main (){

    int num,power;

    cout<<"Enter NUmber : ";
    cin>>num;
    
    cout<<"Enter Power : ";
    cin>>power;

    cout<<calculate_Power(num,power);

    return 0;
}