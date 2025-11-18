#include<iostream>
#include<vector>
#include<stack>>
using namespace std ;

class ListNode {
    public :
    int val;
    ListNode *next;

    ListNode (int val){
        this ->val=val;
        this->next=NULL;
    }
};


class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0){
            return true;
        }

        int lastindex=s.length();
        stack<char> st;

        for(int i=0;i<lastindex;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }

            else {
                if (st.size()==0){
                    return false;
                }

                else if (s[i]==')' || s[i]=='}' || s[i]==']'){
                if(st.size()>0){
                if( (st.top()=='(' && s[i]==')') || (st.top()=='{' && s[i]=='}')  ||(st.top()=='[' && s[i]==']') ){
                    st.pop();
                }
            }
            }
        }
    }
        if(st.size()==0){
            return true;
        }
        else {
            return false;
        }
}
};

int main (){


    return 0;
}
