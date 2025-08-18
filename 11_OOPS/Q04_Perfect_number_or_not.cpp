#include<iostream>
#include<cmath>
using namespace std ;
void PerfectOrNot(int num){
    int sum=1;// initialized sum with 1 as all num divisible by 1 
    if (num==0){
        cout<<"Invalid number to find factors";
        return;
    }
    if(num<0)
        num*=-1;
    
    int UptoVal=sqrt(num);
    for (int i=2;i<=UptoVal;i++){
        if (num%i==0){
            sum+=i; 
            if(num/i!=i){
                sum+=num/i;
            }
        }
    }
    if(sum==num && num!=1){
        cout<<"Perfect number";
    }
    else {
            cout<<"Not a Perfect number";
    }
}
int main (){
int num;
cout<<"Enter the number ";
cin>>num;
PerfectOrNot(num);
    return 0;
}