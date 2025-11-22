#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

// updated q after forward print , print reverse also mean after n to 1 , print  1 to n also 


void print1ton(int i=1, int n){
    if(i==n){
        cout<<n<<", ";
    }
}

void printnto1(int num,int n=1){
    if(n==1){
        cout<<n<<" ";
        return;
    }

    cout<<n<<", ";
    printnto1(n-1);
}


int main (){
    int num;

    cout<<"Enter NUmber : ";
    cin>>num;

    printnto1(num);
    
    return 0;
}