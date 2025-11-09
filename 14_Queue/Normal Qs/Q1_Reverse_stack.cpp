/*
write cpp code to store values in a stack , print all elements , also reverse it and print 
*/

#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std ;


void Print_Queue(queue<int> q){
    int Qlen=q.size(),tempval;
    if (Qlen<=0){
        cout<<"Empty Queue";
        return;
    }
    for (int i=0;i<Qlen;i++){
        cout<<q.front()<<" ";
        tempval=q.front();
        q.pop();
        q.push(tempval);
    }
}

void Reverse_Q(queue<int> Q){
    stack <int> st;
    while (Q.size()>0)
    {
        st.push(Q.front());
        Q.pop();
    }

    while (st.size()>0)
    {
        Q.push(st.top());
        st.pop();
    }
    
    cout<<"Reversal successful \n";
}

int main (){

queue<int> q;

int Queue_len,temp;

cout<<"Enter No of Elments to store in the queue : ";
cin>>Queue_len;

if(Queue_len<=0){
    cout<<"Invalid length, please try again";
    return 0;
}
else {
    cout<<"Enter the elemets \nEnter First Element : ";

}
for(int i=0;i<Queue_len;i++){
    cin>>temp;
    q.push(temp);
    if(i+1!=Queue_len){
        cout<<"\nEnter Next Element : ";
    }
}

Print_Queue(q);

Reverse_Q(q);

Print_Queue(q);

    return 0;
}