/*

#include<iostream>
using namespace std ;

class Node {
public:
    int val;// or int data 
    Node* next;// to store address of the next node
};

int main (){
// eg to enter 10 20 30 40 

Node a;
a.val=10;

Node b;
b.val=20;

Node c;
c.val=30;

Node d;
d.val=40;

// yeah to bikhre hue diff list bane , ab inko link karna hai .. by adress 

a.next=&b;// for all except last node , added the address of the next node 
b.next=&c;
c.next=&d;
d.next=NULL;// only for the last list added the null as no next node needed or available 
    return 0;
}


Lets do the same thing by using constructor , so the lines will bw decreased ;
*/

#include<iostream>
using namespace std;

class Node {
    public : 
    int val;
    Node* next;

    Node(int val){
        this->val=val;
        this->next=NULL;// setting the next adress as null by defaault , so in case we miss anything , it will not go to any random address , instead it will show null , we can modify it later 
    }
};

int main (){

Node a(10),b(20),c(30),d(40);
a.next=&b;
b.next=&c;
c.next=&d;
//d.next=NULL; no needs to write , as already null stored  

// now lets think we need value of c via b ;

cout<<(b.next)->val<<endl;// or we can do like 
cout<<(*(b.next)).val<<endl;// little complex to look but means same , fist value at adress b.next means value at c , Now c have 2 address  1. val 2. address , so accessed by .val (as we need value ) o/p is like 30 
// 30 , so good to go 


// How to get value or Address of next any class using a prev class 
// lets thinkneed value of c by using a ; will do like 

cout<<((a.next)->next)->val<<endl;
/*   ((a.next)                              ->next)                              ->val;
        ^ this a.next , fetch value     b->next , will fetch next value       c->val , fetch the value at c.val
    of next from the a node , which     from b  , which is c ,in easy
    is address of b , so in easy        ((a.next)->next)
    words (a.next)=b                    = b->next = c
      
    
    we can do only .next also all time , but for that we have to do like *(add).next eg next ex
*/

// if need d value by a , we can do 

cout<<(*(*(*a.next).next).next).val<<endl;// last time no need to use next , as we need val, use val only 

/*
      (*(*(*a.next).next).next).val;
    =(*(*(b).next).next).val;
    =(*(*c).next).val
    =(*d).val
    =d.val;


    we can print all the value by using a loop

*/
Node* temp =&a;
while (temp!=NULL){
    cout<<temp->val<<" , "<<endl;
    temp=temp->next;// temp=*(temp.next)
}


    return 0;
}