#include<iostream>
using namespace std;

/*
circular link list just like a cycle in a single list it 

the last or tail node points towards the first node again 

usually q comes like to display or add at tail without maintaining any tail pointer 
hw trying to do actually teacher didnt say not to maintain tail 
but i will try else if i get tail and head already given then very easy to do anything 

i mean like tail->next=newnode
newnode->next=head done , just 2 lines 
*/


class Node{// for circular linked list
    public:
    int val;
    Node* next;

    Node(int value){
        val=value;
        next=NULL;
    }
};

class CircularLinkedList{
    public:
    Node* head;
    //Node* tail; not maintaining as of now 
    //int size; also not maintaining as if size known , easy by a for loop till index 

    CircularLinkedList(){
        head=NULL;
    }
/*
    void AddAt_Head(int value){
        if(head==NULL){
            Node* temp=new Node(value);
            head=temp;
            temp->next=head;// i am confused here ass not teached till now 
            // i mean if only one node to add , will it be a circular list , i mean same node calling 
            // again and again but technically  it should i dont know , please rectify me if wrong ;
            return;// this time will not do same mistake , void so only return 
            // also return will prevent to fall in next cases if any 
        }
        else {// return is enough to stop it , still using else for better redability and easy understanding
            if(head->next==head){// i mean the base case only 1 node;
                Node* temp= new Node(value);
                temp->next=head;
                head->next=temp;
                head=temp;
            }
            else{
                Node *oldhead=head;
                
                /*
                Node *lastnode=head->next;// it cant be null or cant be a single node 
                // as already handelled , so atleast 2 node will be there 
                
                
                while (lastnode->next!=oldhead)
                {
                    lastnode=lastnode->next;
                    }
                    this will take much time , lets optimize it 
                    //
                   Node *lastnode=NULL;
                   Node *lastnode_slow=head->next;
                   Node *lastnode_fast=head->next->next;// LIKE SLOW AND FAST POINTER 
                   
                   while (lastnode==NULL)
                   {
                       if(lastnode_slow->next==oldhead){
                           lastnode=lastnode_slow;
                           break;
                        }
                        else if(lastnode_fast->next==oldhead){
                            lastnode=lastnode_fast;
                            break;
                        }
                        
                        lastnode_slow=lastnode_fast->next;// as already lastnodeslow->next scanned by the fast 
                        lastnode_fast=lastnode_slow->next;// actually its lastnodefast->next(which will be checked by slow
                        //)->next (work as expected slow by 1 , fast by 2 ) so can check 2 at a time 
                    }
                    
                    Node* temp= new Node(value);
                    temp->next=head;
                    lastnode->next=temp;
                    head=temp;
                    
                }
            }
  
    }

 */   
    // actually i over engineered this , lets try again and next addattail and index normal way
    void Addat_Head(int val){
        if(head==NULL){
            Node* temp=new Node(val);
            head=temp;
            temp->next=head;
            return;
        }
        else if(head->next==head){
            Node *temp=new Node(val);
            temp->next=head;
            head->next=temp;
            head=temp;
            return;
        }
        else {
            Node* Lastnode=head->next;
            
            while (Lastnode!=head)
            {
                Lastnode=Lastnode->next;
            }
            
            Node* temp=new Node(val);
            temp->next=head;
            Lastnode->next=temp;
            head=temp;
            
        }
        
    }
    
    void Addat_tail(int val){
        if(head==NULL){
            Node* temp=new Node(val);
            head=temp;
            temp->next=head;
            return;
        }
        else if(head->next==head){
            Node *temp=new Node(val);
            head->next=temp;
            temp->next=head;
            return;
        }
        else {
            Node* lastnode=head->next;
            while (lastnode->next!=head)
            {
                lastnode=lastnode->next;
            }
            Node* temp=new Node(val);
            lastnode->next=temp;
            temp->next=head;
            
        }
        
        
    }
    
    void AddAt_Index(int val ,int index){
        if(index<0){
            cout<<"Invalid Index\n";
            return;
        }
        else if(head==NULL){
            if(index==0){
                Addat_Head(val);
                return;
            }
        else {
            cout<<"Invalid Index\n";
            return;
        }

        }

        else if(index==0){
            Addat_Head(val);
            return;
        }

        else {
            Node *Curr=head;
            for(int i=0;i<index-1;i++){
                if(Curr->next==head){
                    cout<<"Index out of range \n";
                    return;
                }
                Curr=Curr->next;
            }
        Node* temp=new Node(val);
        temp->next=Curr->next;
        Curr->next=temp;
    }
}

};


int main(){



return 0;
}