#include<iostream>
#include<queue>
using namespace std ;
int main (){
/*

follow fifo (first in first out )

actuallly if push from front , pop from back 

queue vs stack 
            Queue                                 stack
    first in first out ,means both         Last in first out (LIFO)
    PUSH,POP OR insert and delete          insert and delete done from opposite ways 
    is done from the top or front          push at top but pop at bottom 
                                           or push from front , but pop from back


                                           
    in queue ellement added from back 
    eg if empty queue , push 10 , 20 

    first   empty 
    push 10   Front Rear :10 
    
    push 20 --> Rear 20     front 10

    push 20     rear 30  20   front 10



    functions include 
    push
    pop 
    front(top)
    size , empty 
    back



    push / insertion is done at back 

    pop in normal queue only happens at front 

    font/top we can access front at o(1)
    back also can be accessed at 0(1)

    empty and size also , if not empty returns false  


    overflow and underflow 

    can only happen if we implement queue using array 

    // display , 

    not any pre defined function , but yes 

    1. store size variable anywhere 
    2. just 
*/


    queue<int> q;

    q.push(10);
    q.push(20);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    return 0;
}