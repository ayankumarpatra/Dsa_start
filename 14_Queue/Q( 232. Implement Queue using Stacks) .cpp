#include<iostream>
#include<stack>
#include<vector>
using namespace std ;

class MyQueue {
public:
    stack<int> st,helper;
    MyQueue() {
        
    }
    
    void push(int x) {// push back

        int stlen=st.size();

        for(int i=0;i<stlen;i++){
            helper.push(st.top());
            st.pop();
        }

        st.push(x);

        stlen=helper.size();

        for(int i=0;i<stlen;i++){
            st.push(helper.top());
            helper.pop();
        }
           
    }
    
    int pop() {
        if(st.size()==0){
            return -1;
        }
        int returnelement=st.top();
        st.pop();
        
        return returnelement;
    }
    
    int peek() {// front 
        if(st.size()==0){
            return -1;
        }

        else{
            return st.top();
        }
    }
    
    bool empty() {
        if(st.size()==0){
            return true;
        }
        else return false;
    }
};

int main (){

    
    return 0;
}