//Smallest Value After Replacing With Sum of Prime Factors
/*
Input: n = 15
Output: 5
Explanation: Initially, n = 15.
15 = 3 * 5, so replace n with 3 + 5 = 8.
8 = 2 * 2 * 2, so replace n with 2 + 2 + 2 = 6.
6 = 2 * 3, so replace n with 2 + 3 = 5.
5 is the smallest value n will take on.
*/

/*


#include<iostream>
#include<cmath>
using namespace std ;

bool primechecker (int num){
    if(num<2) return 0;
    else if(num==2) return 1;
    else if(num%2==0) return 0;
    for (int i=3;i<sqrt(num);i+=2){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}

int smallestValue(int n) {
    if(n<2) return 0;
    if (primechecker(n)) return n;
    int temp=n,sum=0;
    while(temp%2==0){
        sum+=2;
        temp/=2;
    }

    for (int i=3;i<=sqrt(n);i+=2){
        while(temp%i==0){
            sum+=i;
            temp/=i;
        }
    }

    if(temp>1) sum+=temp;
   return smallestValue(sum);
}

int main (){
int num;
cout<<"Enter the number ";
cin>>num;
cout<<smallestValue(num);

    return 0;
}

code is of basic approach but it fails in tihe time complexity of leetcode
*/
