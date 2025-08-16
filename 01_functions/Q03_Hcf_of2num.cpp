#include<iostream>
using namespace std ;
int gcd_finder(int a, int b){
    if (a==0 || b==0){
        cout<<"Invalid numbers to calculate GCD"<<endl;
        return -1;
    }
    if (a<0) a*=-1;
    if (b<0) b*=-1;
    int big= (a>=b)? a:b ,gcd=1;
    for (int i=1;i<big;i++){
        if (a%i==0 && b%i==0)
            gcd=i;
    }
    /*
    or instead of ternary operator we can use min (a,b)
    or the loop part we can reverse like (int i=max;i<=1;i--)
    or Eukledian approach for less time complexity ..
        while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
        return a;
    */
    return gcd;
}
int main (){
int num1,num2;
cout<<"Enter the numbers ";
cin>>num1>>num2;
cout<<"GCD of the numbers is "<<gcd_finder(num1,num2);
    return 0;
}