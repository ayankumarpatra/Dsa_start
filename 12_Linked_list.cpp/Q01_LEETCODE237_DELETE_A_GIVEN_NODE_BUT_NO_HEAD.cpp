//237. Delete Node in a Linked List


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
    void deleteNode(ListNode* node) {
    node->val=node->next->val;
    ListNode*temp=node->next;
    node->next=node->next->next;
    delete(temp);
    }
};
int main (){

    return 0;
}