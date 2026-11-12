#include<iostream>
#include<vector>
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
    ListNode* reverseList(ListNode* head) {
        // i will try both approach 
        // ithink iteration will be faster than recursion based

        // travarsal
        if (head==NULL || head->next==NULL)
        {
        return head;
        }
        
        ListNode* ReverseHead=head;
        head=head->next;
        ReverseHead->next=NULL;
        while (head!=NULL)
        {
        ListNode*temp=head;
        head=head->next;
        temp->next=ReverseHead;
        ReverseHead=temp;
        }
        return ReverseHead;
        
    }
};



class Solution {
public:
    ListNode* Rev(ListNode* ReverseHead,ListNode*head){
            if(head==NULL){return ReverseHead;}

            ListNode*temp=head->next;
            head->next=ReverseHead;
            return Rev(head,temp);
        }

    ListNode* reverseList(ListNode* head) {
        //  recursion based
    return Rev(NULL,head);            
    }
};



// self try

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

    // 3 nodes , front , back , curr = head 
    if (head == NULL){
        return head;
    }

    ListNode * curr = head;
    ListNode * front = curr->next;
    ListNode * back = NULL;

    if ( front== NULL){ return curr; }

    while (front!=NULL)
    {
        front = curr->next;

        curr->next = back;
        back = curr;

        curr = front;
    }
    
    return curr;

    }
};

int main (){


    return 0;
}
