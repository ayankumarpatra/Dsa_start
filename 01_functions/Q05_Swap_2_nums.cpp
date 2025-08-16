#include<iostream>
using namespace std ;
void swipe_number_by3rdvariable(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}

void swipe_number_without_3rdvariable(int *a,int *b){
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
    
}

int main (){
int num1,num2;
cout<<"Enter the numbers ";
cin>>num1>>num2;
cout<<"Before swap numbers are : "<<num1<<" "<<num2<<endl;
swipe_number_by3rdvariable(&num1,&num2);
cout<<"After 1st swap numbers are : "<<num1<<" "<<num2<<endl;
swipe_number_without_3rdvariable(&num1,&num2);
cout<<"After 2nd swap numbers are : "<<num1<<" "<<num2<<endl;
    return 0;
}