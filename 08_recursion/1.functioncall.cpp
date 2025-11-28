// print good morning + name n times take both name and n as user input and function or functions must be recursive. eg hello sam 3 times 

#include<iostream>

using namespace std ;

void Greet(int n, string name){
    if(n==0){
        return;
    }
    cout<<"Good Morning "<<name<<endl;
    Greet(n-1,name);
}


int main (){

    int Times;
    string name;
    cout<<"Enter name : ";
    getline(cin,name);
    cout<<"Enter no of times : ";
    cin>>Times;
    
    Greet(Times,name);

    return 0;
}