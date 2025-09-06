/*

#include<iostream>
using namespace std ;
class ListNode{
    public :
    int val;
    ListNode*next;
    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
};

class LinkedList{
    public:
    ListNode*head;
    int size;
    LinkedList(){
        head=NULL;
        size=0;
    }
};



class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*temp=head;
        int size=0;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        ListNode*temp2=head;
        int mid=size/2;
        for (int i=0;i<mid;i++){
            temp2=temp2->next;
            if (i==size){
                head=temp2;
            }
        }
        return(temp2); 
    }
};


int main (){

    return 0;
}


updated and better 2 pointer algo 


#include<iostream>
using namespace std ;

class ListNode {
    public:
    int val;
    ListNode*next;

    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
    return (slow);  
    }
};

int main (){

    return 0;
}

*/

#include<iostream>
using namespace std ;

class ListNode {
    public:
    int val;
    ListNode*next;

    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
};


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*slow =head;
        ListNode*fast =head;
        while (fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
    return (slow);
    }
};

int main (){

    return 0;
}


