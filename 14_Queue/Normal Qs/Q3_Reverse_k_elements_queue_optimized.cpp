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
    int remaining=q.size()-k;

    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    while (remaining--!=0)// pusing the elements back again to the queue 
    /*
    eg if its 1 2 3 and k=2 , 1 ,2 reversed by stack , after re fill , its 3 2 1 , 
    so just push once 3 2 1 3 , and pop once from front so 2 1 3 and continue till remaining 
    */
    {
        q.push(q.front());
        q.pop();
    }
    /*
    so here what i can reduce , 1. one extra que that i return 
    2. one while loop 
    */
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