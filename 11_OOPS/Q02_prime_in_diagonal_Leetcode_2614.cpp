/*
Return the largest prime number that lies on at least one of the diagonals of nums. In case, no prime is present on any of 
the diagonals, return 0.
*/
#include<iostream>
#include<cmath>
using namespace std ;

bool prime_checker(int num){
    if (num==2 || num==3 ||num==5) return true;
    if (num<=1 || num%2==0 || num%3==0 ||num%5==0) return false;
    int temp=sqrt(num);
    for (int i=7;i<=temp;i++){
        if(num%i==0)
            return false;
    }
    return true;
}

int main (){
    int rows;
cout<<"Enter No of rows or columns : ";
cin>>rows;
int matrix[rows][rows];
for (int i=0;i<rows;i++){
    cout<<"Enter Elements of Row "<<i+1<<endl;
    for (int j=0;j<rows;j++)
        cin>>matrix[i][j];
}
int max=0,element;
for(int i=0;i<rows;i++){
    element=matrix[i][i];
    if(prime_checker(element))
        if (element>max)
            max=element;
}
for(int i=0;i<rows;i++){
    element=matrix[i][rows-i-1];
    if(prime_checker(element))
        if (element>max)
            max=element;
}

cout<<"Max element is : "<<max;
    return 0;
}