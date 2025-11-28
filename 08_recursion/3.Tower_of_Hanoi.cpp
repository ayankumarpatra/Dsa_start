#include<iostream>

using namespace std ;

/*

if n no of disks , min no of moves will be 2^n -1 

*/

void hannoi(int n,char a, char b, char c){//destination
    if(n==0){
        return;
    }

    hannoi(n-1,a,c,b);// to move the n-1 from source a to side stack b by using help of c 

    cout<<a<<"->"<<c<<endl;// moving the last remaining disk to the destination

    hannoi(n-1,b,a,c); // all disk already moved to b , so b now source 
    // moving n-1 from b to a using help of c , 

}

int main (){

    // things that will be passed to tower of hanoi func 

    int n=3;// no of disks

    // A,B,C are the 3 rods 

    hannoi(n,'A','B','C');
    
    return 0;
}