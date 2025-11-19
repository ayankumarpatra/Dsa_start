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

        stack<char> st;

        for(char c:s ){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }

            else {
                if (st.size()==0){
                    return false;
                }

                if( (st.top()=='(' && c==')') || (st.top()=='{' && c=='}')  ||(st.top()=='[' && c==']') ){
                    st.pop();
                }
                else {
                    return false;
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
