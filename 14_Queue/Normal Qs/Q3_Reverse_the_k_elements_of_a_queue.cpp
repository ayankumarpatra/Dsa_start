// q. reverse a queue upto the position given, you can use static inputs , can use stl queue 

#include<iostream>
#include<queue>
#include<stack>
using namespace std ;

void ReverseQueue(queue<int> &q,int k){
    stack<int> st;
    if(k>q.size()){
        cout<<"Given size is more than the actual Queue size \nPlease retry!\n";
        return;
    }
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
    // till stack elements we can reverse easily , or if its deque , we can push from front also 
    // but for normal queue , we cant do , so using and extra queue , then will change the address of the
    // existing queue to the current queue 

    queue<int> returnq;

    while (!st.empty())
    {
        returnq.push(st.top());
        st.pop();
    }
    while (!q.empty())
    {
        returnq.push(q.front());
        q.pop();
    }
    
    q=returnq;
}

void displayq(queue<int> q){
    if(q.empty()){
        cout<<"Empty Queue, no element to display\n";
        return;
    }
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main (){

    queue<int> mainq;

    mainq.push(1);
    mainq.push(2);
    mainq.push(3);
    mainq.push(4);
    mainq.push(5);

    displayq(mainq);
    
    ReverseQueue(mainq,2);
    
    displayq(mainq);

    
    return 0;
}