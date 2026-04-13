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
    void deleteNode(ListNode* node) {
        //given node to be deleted and already given its not the last node 
        
        ListNode *forward=node->next;

        while (forward!=NULL)
        {
            node->val=forward->val;

            if (forward->next==NULL){
                node->next=NULL;
                delete(forward);
                break;
            }
            node=node->next;
            forward=forward->next;
        }
        
    }
};

int main (){


    return 0;
}
