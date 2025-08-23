#include<iostream>
#include<cmath>
using namespace std ;

int minSteps(int num){
    if (num==1){
        return 0;
    }
    int steps =0;
    for (int factor=2;factor*factor<=num;factor++){
        while(num%factor==0){
            steps+=factor;
            num/=factor;
        }
    }
    if(num>1) {
        steps+=num;
    }
    return steps;
}

int main (){

    return 0;
} 

/*
i like the basic logic as i have done it by self , so i am keeping it
bool isprime (int num){
    if(num<2){
        return 0;
    }
    if(num==2){
        return 1;
    }
    if(num%2==0){
        return 0;
    }
    for (int i=3;i<=sqrt(num);i+=2){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}

int minSteps(int num){
    if(num==0){
        return 0;
    }
    if (num<0){
        return -1;
    }
    if(num==1){
        return 2;
    }
    if (isprime(num)){
        return num;
    }
    if (isprime(num/2)){
        return (num/2)+2;
    }
  int steps=0,factor=2;
  while (num>1){
    if(num%factor==0){
        steps+=factor;
        num/=factor;
    }
    factor++;
  }
  return steps;
    }

*/