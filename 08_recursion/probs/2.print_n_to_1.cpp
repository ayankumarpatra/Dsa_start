/*

#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

// updated q after forward print , print reverse also mean after n to 1 , print  1 to n also 


void print1ton(int n, int i=1){
    if(i==n){
        cout<<n<<", ";
        return;
    }

    cout<<i<<", ";
    print1ton(n,i+1);
}

bool once =true;
int temp;

void printnto1(int n){
    if(n==1){
        cout<<n<<" ";
        if (once){
        temp=n;
        once=false;
    }
    cout<<endl;
    print1ton(temp);

        return;
    }

    if (once){
        temp=n;
        once=false;
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


beter and optimized version for the q , first print n to 1 , then  print  1 to n also 

*/

#include<iostream>

using namespace std ;

void print1_to_n(int n){// just experimented reverse recursion 
    if(n==1){
        cout<<"1";
        return;
    }

    print1_to_n(n-1);
    cout<<n<<", ";
    
}

void printn_to_1(int n){
    if(n==1){
        cout<<"1"<<endl;
        return;
    }

    cout<<n<<", ";
    printn_to_1(n-1);
}

void printboth(int n){

    printn_to_1(n);
    cout<<endl;

    print1_to_n(n);
    cout<<endl;

}

int main (){

    int num;

    cout<<"Enter NUmber : ";
    cin>>num;

    printboth(num);

    return 0;
}