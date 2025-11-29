#include<iostream>

using namespace std ;

void Hanoi(int n,char a,char b, char c){
        if(n==0){// base case if n=0 , no disk left so return 
            return;
        }
    // first move n-1 disks from a to b , helping c . source , helper , dest 

    Hanoi(n-1,a,c,b);

    // now move the last disk from a to c ,

    cout<<a<<" -> "<<c<<endl;

    // now b is the source so move n-1 back to a , to a help of c 

    Hanoi(n-1,b,a,c);

}


int main (){

    Hanoi(3,'A','B','C');
    
    return 0;
}