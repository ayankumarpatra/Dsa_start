#include<iostream>
using namespace std ;

class ListNode{
    public:
    int val;
    ListNode*next;

    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
};

class LinkedList {
    public:
    ListNode*head;
    ListNode*tail;
    int size;

    LinkedList(){
        head=NULL;
        size=0;
    }

    void Add_At_Tail(int value){
        if(size==0){
            ListNode*temp;
            temp->val=value;
            head=tail=temp;
            size++;
        }
        else if(size>0){
            ListNode*temp;
            temp->val=value;
            tail->next=temp;
            tail=temp;
            size++;
        }
    }

};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *Node1=list1;
        ListNode *Node2=list2;

        
        if(!Node1){/*Node 1 is null so returning node 2 */ return list2;}
        else if(!Node2){return list1;}
        
        LinkedList ResultNode;


        while (Node1!=NULL && Node2!=NULL)
        {
            if(Node1->val<=Node2->val){
                ResultNode.Add_At_Tail(Node1->val);
                Node1=Node1->next;
            }

            else {
                ResultNode.Add_At_Tail(Node2->val);
                Node2=Node2->next;
            }
        }
        if(Node1!=NULL){
            ResultNode.tail->next=Node1;
        }
        else if(Node2!=NULL){
            ResultNode.tail->next=Node2;
        }

        return ResultNode.head;

    }
        
};




int main (){

    return 0;
}