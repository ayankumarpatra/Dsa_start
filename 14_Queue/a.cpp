#include<iostream>
#include<stack>
#include<vector>
using namespace std ;

class MyQueue {
public:
    stack<int> st,helper;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if(st.size()==0){
            return -1;
        }
        int toremove=st.size();

        for(int i=0;i<toremove-1;i++){
            helper.push(st.top());
            st.pop();
        }

        int returnelement=st.top();
        st.pop();

        toremove=helper.size();
        //for(int i=0;i<

    }
    
    int peek() {// front 
        
    }
    
    bool empty() {
        
    }
};

int main (){

    
    return 0;
}