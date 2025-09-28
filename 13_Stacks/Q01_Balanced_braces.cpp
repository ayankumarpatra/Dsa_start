// check if a eqn have matching braces or not (check for single brace '(' only )

// q was just to check if matching braces , but i modified 
// 1. travarse through eqn , anf first brace we get is the brace to check, didnt check for constant ( only 

#include<iostream>
#include<stack>
using namespace std ;

char GetFirstBrace(string str){
    if(str.length()==0){
        return '\0';
    }
    int sz=str.length();
    for(int i=0;i<sz;i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            return str[i];
        }
    }
    return '\0';
}

bool IsBalanced(string str){
    // if(str.length()%2!=0){
    //     return false;
    // };// sir said , but this will only work if braces are there , not an equation 8+(3*4), len is 7 but braces are balanced p
    if(str.length()<=1){
        cout<<"\nInvalid string to check \n";;
        return false;// if length is <=1 , either maybe 1 brace or any 1 operand or any 1 thing is there , no valid point to check for balance
    }
    char FirstBrace=GetFirstBrace(str);
    if(FirstBrace=='\0'){
        cout<<"\nInvalid string to check \n";;
        return false;       
    }
    char Endbrace;
    if(FirstBrace=='(') Endbrace=')';
    else if(FirstBrace=='{') Endbrace='}';
    else if(FirstBrace=='[') Endbrace=']';
    stack<char> st;
    for (int i=0;i<str.length();i++){
        if(str[i]==FirstBrace){
            st.push(str[i]);
        }
        if(str[i]==Endbrace){
            st.pop();
        }
    }

    if(st.size()==0){
        cout<<"Braces are matching \n";
        return true;
    }
    else {
        cout<<"Braces arent matching \n";
        return false;
    }

}

int main (){
    char Equation [50];
    cout<<"Enter the equation : ";
    cin>>Equation;

    IsBalanced(Equation);


    return 0;
}