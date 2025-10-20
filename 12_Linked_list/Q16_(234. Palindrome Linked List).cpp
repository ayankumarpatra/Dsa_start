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
    bool isPalindrome(ListNode* head) {
        vector <int> MainNum;
        while (head!=NULL)
        {
        MainNum.push_back(head->val);
        head=head->next;
        }
        vector<int> ReversedNum;
        ReversedNum=MainNum;
        reverse(ReversedNum.begin(),ReversedNum.end());
        if(MainNum==ReversedNum){
            return true;
        }
        else {
            return false;
        }
        
    }
};


int main (){


    return 0;
}
