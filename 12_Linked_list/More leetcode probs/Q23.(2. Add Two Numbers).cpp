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
/*
failed attempt 1 




class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1=0;
        int num2=0;

        bool num1end=false,num2end=false;

        ListNode* num1pointer =l1;
        ListNode* num2pointer =l2;

        while (!num1end && !num2end)
        {
           if (!num1end){
            num1=(num1*10)+num1pointer->val;

            if (num1pointer->next==NULL){
                num1end=true;
            }

            else {
                num1pointer=num1pointer->next;
            }
           }

           if (!num2end){
            num2=(num2*10)+num2pointer->val;

            if (num2pointer->next==NULL){
                num2end=true;
            }

            else {
                num2pointer=num2pointer->next;
            }
           }
        }

           int sum=num1+num2;

           int tempval=sum%10;
           sum=sum/10;

           ListNode* returnhead=new ListNode(tempval);

           while (sum>0)
           {
            int tempval=sum%10;
            sum=sum/10;

            ListNode* tempnode=new ListNode(tempval);

            tempnode->next=returnhead;
            returnhead =tempnode;

           }
           
        return returnhead;
        
    }
};
*/


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0,sum=0;

        ListNode* returnnode=new ListNode(1);
        ListNode* addnode= returnnode;



        while ( l1!=NULL || l2!=NULL || carry>0)
        {
            sum=carry;
            // handling num 1
           if (l1!=NULL){
            sum+=l1->val;
            l1=l1->next;          
        }

        // handling num2

        if (l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
           }

           carry=sum/10;

           int tempval=sum%10;

           ListNode *tempnode= new ListNode(tempval);

            addnode->next=tempnode;
            addnode=tempnode;
        }

        while (carry>0){
            int tempval=carry%10;
            carry=carry/10;

           ListNode *tempnode= new ListNode(tempval);

            addnode->next=tempnode;
            addnode=tempnode;
        }


        return returnnode->next;

    }
};


int main (){


    return 0;
}
