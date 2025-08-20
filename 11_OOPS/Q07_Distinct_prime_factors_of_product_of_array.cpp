#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std ;

bool isprime (int num){
    if (num<2) return false;
    if(num==2)  return 2;
    if (num%2==0) return 0;
    for(int i=3;i<sqrt(num);i++){
        if (num %i==0)
            return 0;
    }
    return 1;
}

int distinctPrimeFactors(int *nums) {
    int max=*nums,length = sizeof (nums);
    for (int i=0;i<length;i++){
        if (max<*(nums+i)){
            max=*(nums+i);
        }
    }

    int flag=0,maxcontain=10,added=0,elm=0;

    int*elements = (int*)malloc(10*sizeof(int));
    if (max>2) elements[added++]=2;
    for (int i =3;i<max;i+=2){
        if (isprime(i)){
            elements[added++]=i;
        }
        if (maxcontain>=added){
            int *temp= (int *)realloc(elements,20*sizeof(int));
            maxcontain+=10;
        }
    }
    for (int j=3;j<length;j+=2){
        

    }
        for (int i=0;i<length;i++){
}


}
int main (){
int nums;
cout<<"Enter approximate number of numbers : ";
cin>>nums;

int * arr = (int*) malloc (nums*sizeof(int));

if(arr==NULL){
    cout<<"Memory allocation failed , please retry";
    return 1;
}
cout<<"Enter the elemets separated by spaces \n ";
distinctPrimeFactors(arr);

    return 0;
}