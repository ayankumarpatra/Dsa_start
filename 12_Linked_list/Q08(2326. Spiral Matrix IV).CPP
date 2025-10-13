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

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode* Curr_Pos=head;
        vector<vector<int>> Fill_Matrix(m,vector<int>(n,-1));
        int top=0,bottom=m-1;
        int left=0,right=n-1;

        while(Curr_Pos && top <=bottom && left<=right){
            // moving left to right
            for(int j=left;j<=right && Curr_Pos;j++){
                Fill_Matrix[top][j]=Curr_Pos->val;
                Curr_Pos=Curr_Pos->next;
            }
            top++;

            for(int i=top;i<=bottom && Curr_Pos;i++){
                //moving top to bottom
                Fill_Matrix[i][right]=Curr_Pos->val;
                Curr_Pos=Curr_Pos->next;
            }
            right--;

            for(int j=right ;j>=left && Curr_Pos;j--){
                //moving right to lrft 
                Fill_Matrix[bottom][j]=Curr_Pos->val;
                Curr_Pos=Curr_Pos->next;
            }
            bottom--;

            for (int i=bottom;i>=top && Curr_Pos;i--){
                Fill_Matrix[i][left]=Curr_Pos->val;
                Curr_Pos=Curr_Pos->next;
            }
            left++;


        }

        return Fill_Matrix;

    }
};



int main (){


    return 0;
}
