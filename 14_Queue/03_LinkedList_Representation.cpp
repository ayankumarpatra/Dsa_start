#include<iostream>
#include<stack>
#include<vector>

using namespace std;
/*
push back 
pop front 

front ..... back 


options 

1.Push insertat tail
2. pop deleteathead
3. front = head val , top = tail val 
4. size as linkedlist size 
*/

class node {
    public:
    int val;
    node*next;

    node(int val){
        this->val=val;
        next=NULL;
    }

};


class LinkedList_Queue{
    public:
    node* head;
    node* tail;
    int size;

    LinkedList_Queue(){
        head=tail=NULL;
        size=0;
    }

    void push (int num){//insertatTail, push back
        node* temp=new node(num);
        if (size==0){
            head=tail=temp;
            size++;
        }
        else {
            tail->next=temp;
            tail=temp;
            size++;
        }
    }

    void pop(){// pop front , delete front
        if (size==0){
            cout<<"Empty Queue , cant pop\n";
            return;
        }
        else {
            node* temp=head->next;
            delete(head);
            head=temp;
            size--;
        }
    }

    int rear(){
        if (size==0){
            cout<<"Empty Queue no top element \n";
            return -1;
        }
        else {
            return tail->val;
        }
    }

    int front(){
        if (size==0){
            cout<<"Empty Queue ,no element \n";
            return -1;
        }
        else {
            return head->val;
        }
    }

    void Display(){
        if (size==0){
            cout<<"Empty Queue ,no element \n";
            return;
        }
        else {
            node* temp=head;
            while (temp!=NULL)
            {
                cout<<temp->val<<" ";
                temp=temp->next;
            }
            
        }    
        
    }
};

int main (){
LinkedList_Queue lq;
int choice;
do {
    cout<<"\nAvailable options are :\n1.push 2.pop\n3.get rear element 4.get front element\n5.display 6.Any other key to exit\nEnter your choice:";
    cin>>choice;

    switch (choice)
    {
        case 1:int element;
                cout<<"Enter Element to push : ";
                cin>>element;
                lq.push(element);
                break;
        case 2: lq.pop();
                break;
        case 3: cout<<"Rear element is "<<lq.rear()<<endl;
                break;
        case 4 : cout<<"Front element is "<<lq.front()<<endl;
                break;
        case 5 : lq.Display();
                break;
        default: cout<<"exitting program\n";
                return 0;
    }

}while(choice!=0);
    
    return 0;
}

/*
Advantage of linked list implementation of queue over array implementation
1. unlimited size
2. no wastage of size 
3. normal not complex implementation like a normal linked list 


*/