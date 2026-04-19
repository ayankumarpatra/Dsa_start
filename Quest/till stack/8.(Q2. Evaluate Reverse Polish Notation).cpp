#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std ;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int maxlen=tokens.size()-1;
        stack <int> st;

    for (int i=0;i<=maxlen;i++){

        if (st.size()>0 && tokens[i]=="+"){
            int temp2=st.top();
            st.pop();
            int temp1=st.top();
            st.pop();
            
            st.push(temp1+temp2);
        }
        
        else if (st.size()>0 && tokens[i]=="-"){
            int temp2=st.top();
            st.pop();
            int temp1=st.top();
            st.pop();
            
            st.push(temp1-temp2);
        }
        
        else if (st.size()>0 && tokens[i]=="/"){
            int temp2=st.top();
            st.pop();
            int temp1=st.top();
            st.pop();
            
            st.push(temp1/temp2);
        }
        
        
        else if (st.size()>0 && tokens[i]=="*"){
            int temp2=st.top();
            st.pop();
            int temp1=st.top();
            st.pop();
            
            st.push(temp1*temp2);
        }

        else {
            st.push(stoi(tokens[i]));
        }
    }

    return st.top();

    }
};


int main (){

    
    return 0;
}