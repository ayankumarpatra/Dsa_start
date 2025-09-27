// check if a eqn have matching braces or not (check for single brace '(' only )

// q was just to check if matching braces , but i modified 
// 1. travarse through eqn , anf first brace we get is the brace to check, didnt check for constant ( only 

#include<iostream>
#include<stack>
using namespace std ;

char Brace;

char FirstBrace(string str){
    if(str.length()==0){
        return NULL;
    }
    int sz=str.length();
    for(int i=0;i<sz;i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
    }
}

bool IsBalanced(string str){
    if(str.length()%2!=0){
        return false;
    }
    stack<char> st;
    for (int i=0;i<str.length();i++){
        if(str[i]=='('){

        }
    }

}

int main (){

    cout<<"E";

    return 0;
}