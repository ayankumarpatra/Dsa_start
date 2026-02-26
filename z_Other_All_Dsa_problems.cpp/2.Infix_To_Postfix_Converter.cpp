#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

int operatorPrecedence(char ch){
    if (ch=='^') return 3;
    else if (ch=='/' || ch=='*') return 2;
    else if (ch=='+' || ch=='-') return 1;

    else return 0;// not an operator 
}

bool isrightPrecedence(char ch){
    if(ch=='^'){
        return true;
    }
    return false;
}

bool isoperator(char ch){
    if (ch=='+' || ch=='-' ||ch=='*' || ch=='/' || ch=='^'){
        return true;
    }
    return false;
}

string postfixconverter(const string &str){
    string postfix;
    stack<char> st;

    for(char ch :str){
        if(isoperator(ch)){// if operator
            if (st.empty()){
                st.push(ch);
            }
            else if (!st.empty() && operatorPrecedence(st.top())<operatorPrecedence(ch)){
                st.push(ch);
            }
            else if (!st.empty() && operatorPrecedence(st.top())==operatorPrecedence(ch) && isrightPrecedence(ch) ){
                st.push(ch);
            }
            
            else {
                while (!st.empty() && operatorPrecedence(st.top())>=operatorPrecedence(ch))
                {
                    postfix+=st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        else if (ch=='('){
            st.push(ch);
        }
        else if (ch==')'){
            while (st.top()!='(')
            {
                postfix+=st.top();
                st.pop();
            }
            st.pop();
        }

        else {
            postfix+=ch;
        }
    }
    
    while (!st.empty())
    {
        postfix+=st.top();
        st.pop();
    }
    
    return postfix;
}


int main (){

    string str;

    cout<<"Enter the infix expression ";
    getline(cin,str);

    cout<<"infix string is : "<<str<<endl;

    string postfix=postfixconverter(str);
    cout<<"postfix converted string is : "<<postfix<<endl;
    
    return 0;
}