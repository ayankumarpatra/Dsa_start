// 23.Merge k Sorted Lists

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
    ListNode *Merge2List(ListNode*list1,ListNode*list2){
        if(list1==NULL){return list2;}
        else if(list2==NULL){return list1;}

        ListNode*Resultnode=new ListNode(-1);
        ListNode*ResultNodeHead=Resultnode;
        if(list1==NULL){return list2;}
        else if (list2==NULL){return list1;}

        while (list1!=NULL && list2!=NULL)
        {
            if(list1->val<=list2->val){
                Resultnode->next=list1;
                list1=list1->next;
                Resultnode=Resultnode->next;
            }

            else if(list1->val>list2->val){
                Resultnode->next=list2;
                list2=list2->next;
                Resultnode=Resultnode->next;
            }
        }
        if(list1!=NULL){Resultnode->next=list1;}
        else if (list2!=NULL){Resultnode->next=list2;}

        return ResultNodeHead->next;
        
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int No_Of_Lists=lists.size();
        int i,NoOfNodes;
        if(lists.empty()){
            return nullptr;
        }
        while (lists.size()>1)
        {
        vector<ListNode*> Templist;
        for(int i=0;i<lists.size();i+=2){
            if(i+1<lists.size()){
                Templist.push_back(Merge2List(lists[i],lists[i+1]));

            }
            else {
                Templist.push_back(lists[i]);
            }
        }
        lists=Templist;
    }  

    return lists[0];    
    }
};

int main (){


    return 0;
}