/*
#include<iostream>
using namespace std ;

class Node {
    public :
    int val;
    Node *next;

    Node (int val){
        this ->val=val;
        this->next=NULL;
    }
};

class Linkedlist {
    public:
    Node* head;
    int size;

    Linkedlist(){ 
        head=NULL;
        size=0;
    }
};

void InsertAtHead(Node *&head ,int &size,int val){
    Node *temp= new Node(val);
    temp->next=head;
    head=temp;
    size++;
}


void display (Node *head){
    if (head==NULL){
        cout<<"Empty list , nothing to print \n";
        return;
    }
    Node *temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

class Solution {
public:
    Node* deleteDuplicates(Node* head) {
        if (head==NULL){
            return NULL;
        }
        Node *temp= head;

        while (temp!=NULL && temp->next!=NULL)
        {   if(temp->val==temp->next->val){
            temp->next=temp->next->next;
            }
            
        else {
         temp=temp->next;
        }
    }
        return temp;  
    }
};


int main (){


    return 0;
}



#include<iostream>
using namespace std ;

class Node {
    public:
        int val;
        Node* next;
        Node(int value){
        val=value;
        next=NULL;
    }
};

class LinkedList{
    public:
    Node* head;
    Node* tail;
    int size;
    LinkedList(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    
    void AddAtTail(int val){
        if(size==0){
            Node* temp =new Node(val);
            head=tail=temp;
            size++;
        }
        else {
            Node * temp=new Node(val);
            tail->next=temp;
            tail=temp;
            size++;
        }
    }
    
    void display(){
        if(size==0){
            cout<<"empty list\n";
            return;
        }
        cout<<"\nElements are :\n";
        Node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    
    void reverse(){
        // i will try both approach 
        // ithink iteration will be faster than recursion based
        
        // travarsal
        if (head==NULL || head->next==NULL)
        {
            return;
        }
        
        Node* ReverseHead=head;
        head=head->next;
        ReverseHead->next=NULL;
        while (head!=NULL)
        {
            Node*temp=head;
            head=head->next;
            temp->next=ReverseHead;
            ReverseHead=temp;
        }
        head= ReverseHead;
        
    }
};


int main (){
    int No_of_elements,number;
    LinkedList ll;
    cout<<"Enter The no of values you want to add :";
    cin>>No_of_elements;
    while (No_of_elements>0)
    {
        cout<<"Enter The value you want to add :";
        cin>>number;
        ll.AddAtTail(number);
        No_of_elements--;
    }
    ll.display();
    ll.reverse();
    ll.display();
    
    return 0;
}
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

class ListNode {
    public :
    int val;
    ListNode *next;

    ListNode (int val){
        this ->val=val;
        this->next=NULL;
    }
};

class Solution {
public:
    ListNode* ReverseList(ListNode* MainList){
        if(MainList==NULL || MainList->next==NULL){
            return MainList;
        }
        ListNode* Reversehead=MainList;
        ListNode*temp;
        MainList=MainList->next;
        Reversehead->next=NULL;

        while (MainList!=NULL)
        {
        temp=MainList;
        MainList=MainList->next;
        temp->next=Reversehead;
        Reversehead=temp;
        }

        return Reversehead;
        

    }


    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;

        while (fast!=NULL && fast->next!=NULL)
        {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
        }
        // now slow is the mid;
        prev->next=NULL;

        slow=ReverseList(slow);

        while (slow!=NULL && head!=NULL)
        {
        if(head->val!=slow->val){
            return false;
        }
        head=head->next;
        slow=slow->next;
        }
       return true; 
    }
};


int main (){


    return 0;
}
