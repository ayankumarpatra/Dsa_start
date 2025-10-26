#include<iostream>
using namespace std;

/*
optimizing means , for every add delete or get function 
    just check index and decide from where you have to travarse i mean head or tail 

    eg if size is 100 and have to do any operation at 99 th node , will travarse from tail 
    i mean it will not optimize each casse but surely optimize some cases 





creating functions to 
1. insert (head , tail , index )
2. delete (head , tail , index )
3. get value (head , tail , index )
*/


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

class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;
    int size;

    DoublyLinkedList(){
    head=tail=NULL;
        size=0;
    }

    void AddAthead(int val ){
        if(size==0){
            Node * temp= new Node(val);
            head=tail=temp;
        }
        else if (size>0){
            Node* temp= new Node(val);
            temp->next=head;
            head->prev=temp;
            head=temp;
        }

        size++;
    }


    void displayLinkedListByHead(Node *head){
        Node*temp = head;
        if (temp==NULL){
            return;
        }
        cout<<temp->val<<" ";
        displayLinkedListByHead(temp->next);
    }

        void displayLinkedListByTail(Node *tail){
        Node*temp = tail;
        if (temp==NULL){
            return;
        }
        cout<<temp->val<<" ";
        displayLinkedListByTail(temp->prev);
    }


    /*
    Node if we interchange the print and recursive call lines , it will also print the  list but in reverse order ;

    eg 
            cout<<temp->val<<" ";
        displayLinkedListByTail(temp->prev);// this will print tail to head ( already in reverse )
        // but if we do 

        displayLinkedListByTail(temp->prev);
                cout<<temp->val<<" ";// it will print the list in foward order eg head -> tail 
                becuase every  time value stored in the stack , later popinng out so printing again reverse so reverse of reverse is forward
    
    */


        void AddAtTail(int val ){
        if(size==0){
            Node * temp= new Node(val);
            head=tail=temp;
        }
        else if (size>0){
            Node * temp= new Node(val);
            tail->next=temp;
            temp->prev=tail;
            tail=temp;

        }
        size++;
    }

    void InsertAt_Index(int index, int val){// taking index as proper index like c++, eg indexing start with 0 , ends at size-1;
        if (index<0 || index>size){
            int temp;
            cout<<"Invalid index given \nChoose from bellow options \n1.Retry 2.press any other key to exit \nEnter your choice: ";
            cin>>temp;
            if(temp==1){
                cout<<"\nEnter index : ";
                cin>>temp;// reusing same temp again instead of using other variable 
                InsertAt_Index(temp,val);
            }
            else{
                return;
            }
        }
        if (index==0){
            AddAthead(val);
            return;
        }
        else if (index==size){
            AddAtTail(val);
            return;
        }
        else {
            Node * curr=head;
            Node * NodeToAdd=new Node(val);
            for (int i=0;i<index-1;i++){
                curr=curr->next;
            }

            Node*Nextnode = curr->next;
            // curr=curr->prev;// moving curr back to the prev pos if done the for (int i=0;i<index;i++) to index 

            curr->next=NodeToAdd;
            NodeToAdd->prev=curr;

            NodeToAdd->next=Nextnode;
            Nextnode->prev=NodeToAdd;
        }
    }


    //2. delete (head , tail , index )

    void DeleteHead(){
        if(size==0){
            cout<<"Empty List to delete\n";
            return;
        }
        else if(size==1){
            Node* temp=head;
            head=tail=NULL;
            delete(temp);
            size--;
            return;
        }
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        delete(temp);
        size--;
    }

    void DelTail(){
         if(size==0){
            cout<<"Empty List to delete\n";
            return;
        }
        else if(size==1){
            Node* temp=tail;
            head=tail=NULL;
            delete(temp);
            size--;
            return;
            
        }
        Node * temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete(temp);
        size--;
        return;
    }

    void DelAt_Index(int index){
        if(index<0 || index>=size){
            cout<<"Invalid index , please retry\n";
            return;
        }
        else if(index==0){
            DeleteHead();
            return;
        }
        else if(index==size-1){
            DelTail();
            return;
        }
    
        else {
            Node*curr=head;

            for(int i=0;i<index-1;i++){
                curr=curr->next;
            }

            Node*temp=curr->next;

            curr->next=curr->next->next;
            curr->next->next->prev=curr;

            delete(temp);
            size--;
        }
    }



    //get value (head , tail , index )

    int GetHead_Value(){
        if(size==0){
            cout<<"Empty list , cant fetch value \n";
            return -1;
        }
        return head->val;
    }
    
    int GetTail_Value(){
        return tail->val;
        
    }
    
    int GetIndex_Value(int index){
        if(index<0 || index>=size){
            cout<<"Invalid Index , cant fetch value \n";
            return -1;
        }
        else {
            Node * curr=head;// Note i writeen on the base of indexing start with 0 , if user think index start from 1 , code will be
            // little diff just make the function code index= index -1 , as code enviornment cant start index from 1 
            for(int i=0;i<index;i++){
                curr=curr->next;
            }
            return curr->val;
        }
        
    }
    
    // display
    
    void Display(){
        if(size==0){
            cout<<"Empty list , cant fetch value \n";
            return;
        }
        else {
            Node * curr=head;
            while (curr!=NULL)
            {
            cout<<curr->val<<" ";
            }
            cout<<endl;
            
        }
        
    }


};


int main(){



return 0;
}