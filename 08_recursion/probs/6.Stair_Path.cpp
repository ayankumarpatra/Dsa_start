// calculate a^b and return value 

#include<iostream>

using namespace std ;


int calculate_Power(int num,int power){

    if(power==0){
        return 1;
    }

    else if(power==1){
        return num;
    }

    int ans = calculate_Power(num,power/2);

    if(power%2==0){

        return ans*ans;
    }

    else if(power%2!=0){
        return num*ans*ans;
    }

    return 0;
}

int main (){

    int num,power;

    cout<<"Enter NUmber : ";
    cin>>num;
    
    cout<<"Warning ! This version only works for positive and non negetive integer power \n";
    cout<<"Enter Power accordingly : ";
    cin>>power;

    cout<<num<<"^"<<power<<" = "<<calculate_Power(num,power);

    return 0;
}