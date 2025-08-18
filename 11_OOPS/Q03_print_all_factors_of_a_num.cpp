#include<iostream>
#include<cmath>
using namespace std ;
/*
We can run a loop also from i =1 to n , but time complexity will be much more 

so we can reduce the loop to sqrt num and later number will be num/i

eg if num is 60 , factors are 
         1 2 3 4 5 6 10 12 15 20 30 60
now dont know sqrt of 60 but 8 ^2 is 64 , so its less than 8 , 

so will run the loop till sqrt(60) and then will print 60 /i also for each divisor founnd till 60

*/
void FactorFinder(int num){
    if (num==0){
        cout<<"Invalid number to find factors";
        return;
    }
    if(num<0)
        num*=-1;
    
    int UptoVal=sqrt(num);
    for (int i=1;i<=UptoVal;i++){
        if (num%i==0)
            cout<<i<<" , ";
            if(num/i!=i)
                cout<<num/i<<" , ";
        
    }
}
int main (){
int num;
cout<<"Enter the number ";
cin>>num;
FactorFinder(num);
    return 0;
}