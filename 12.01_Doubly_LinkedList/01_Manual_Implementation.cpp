#include<iostream>
using namespace std;

class Node{// for doubly linked list
    public:
    Node* prev;
    int val;
    Node* next;

    Node(int value){
        prev=NULL;
        val=value;
        next=NULL;
    }
};

class LinkedList{
    public:
    Node* prev;
    int val;
    Node* next;
    int size;

    LinkedList(int value){
        prev=NULL;
        val=value;
        next=NULL;
        size=0;
    }

    void AddAthead(int val ){
        if(size==0){
            
        }
    }
};


int main(){



return 0;
}