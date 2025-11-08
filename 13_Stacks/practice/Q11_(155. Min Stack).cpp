#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std ;

class MinStack {
public:
    stack<int> st;
    stack<int> minv;

    MinStack() { }// minstack constructor
    
    void push(int val) {
        if(minv.empty() || val<=minv.top()){
            minv.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        if(minv.size()>0 && st.top()==minv.top()){
            minv.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minv.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 * 
 */
int main (){

    return 0;
}