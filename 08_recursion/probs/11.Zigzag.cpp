#include<iostream>
using namespace std ;

/*
q. print zig zag output and take user input of no of levels , 
zigzag o/p is like this
if input 1 op is 111
if      2       211121112
if      3       321112111232111211123....

zig zag is a similar structure like the pre in post ;

*/

void PrintZigZag(int base){
    if(base==0){return;}
    // pre
        cout<<base<<" ";
        PrintZigZag(base-1);
    // in
        cout<<base<<" ";
        PrintZigZag(base-1);
    //post
        cout<<base<<" ";
}

int main (){

    int levels;
    cout<<"Enter No of levels : ";
    cin>>levels;

    PrintZigZag(levels);
    
    return 0;
}