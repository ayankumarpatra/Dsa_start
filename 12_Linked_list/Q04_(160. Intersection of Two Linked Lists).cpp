#include<iostream>
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

class Linkedlist {
    public:
    ListNode* head;
    int size;

    Linkedlist(){ 
        head=NULL;
        size=0;
    }
};

void InsertAtHead(ListNode *&head ,int &size,int val){
    ListNode *temp= new ListNode(val);
    temp->next=head;
    head=temp;
    size++;
}


void display (ListNode *head){
    if (head==NULL){
        cout<<"Empty list , nothing to print \n";
        return;
    }
    ListNode *temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


/*


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==headB){
            return headA;
        }
        ListNode * temp1= headA;
        ListNode * temp2;

        while (temp1!=NULL){
            temp2= headB;
            while (temp2 != NULL){
            if(temp1==temp2){
                return temp1;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
        }
        return NULL;
    }
};


// My basic code , doing in fast approach 1 , length diff method 


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==NULL || headB==NULL){
            return NULL;
        }
        ListNode *lista=headA;
        ListNode *listb=headB;
        int lena=0,lenb=0,longlen;
        while (lista!=NULL){
            lista=lista->next;
            lena++;
        }
        while (listb!=NULL){
            listb=listb->next;
            lenb++;
        }
        ListNode * longlist;
        ListNode * shortlist;
        if (lena>lenb){
            longlist=headA;
            shortlist=headB;
            longlen=lena;
        }
        else {
            longlist=headB;
            shortlist=headA;
            longlen=lenb;
        }
        int tillgoval=abs(lena-lenb);
        for (int i=0;i<tillgoval;i++){
            longlist=longlist->next;
        }
        while (longlist!=NULL){
            if (shortlist==longlist){
                return shortlist;
            }
            longlist=longlist->next;
            shortlist=shortlist->next;
        }
        return NULL;     
    }
};

*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB){
            return NULL;
        }
        ListNode *nodea=headA;
        ListNode *nodeb=headB;

        while (nodea!=nodeb){
            nodea=(nodea==NULL)? headB : nodea->next;
            nodeb=(nodeb==NULL)? headA : nodeb->next;
        }
        return nodea;
    }
};
int main (){


    return 0;
}
