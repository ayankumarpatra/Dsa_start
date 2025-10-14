#include<iostream>
#include<vector>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode*next;

    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
};

class Linkedlist{
    public:
    ListNode*head;
    int size;

    Linkedlist(){
        head=NULL;
        size=0;
    }
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>> Fill_Matrix(m,vector<int>(n,-1));
    
    ListNode*Curr_Node=head;

    int Start_Row=0,Max_Row=m-1;
    int Start_Col=0,Max_Col=n-1;

    while(Start_Row<=Max_Row && Start_Col<=Max_Col){
        //left to right
        for(int i=Start_Col;i<=Max_Col && Curr_Node;i++){
            Fill_Matrix[Start_Row][i]=Curr_Node->val;
            Curr_Node=Curr_Node->next;
        }
        Start_Row++;

        //top to bottom
        for(int i=Start_Row;i<=Max_Row && Curr_Node;i++){
            Fill_Matrix[i][Max_Col]=Curr_Node->val;
            Curr_Node=Curr_Node->next;
        }
        Max_Col--;

        //right to left
        for(int i=Max_Col;i>=Start_Col && Curr_Node;i--){
            Fill_Matrix[Max_Row][i]=Curr_Node->val;
            Curr_Node=Curr_Node->next;
        }
        Max_Row--;
        
        //bottom to top
        for(int i=Max_Row;i>=Start_Row && Curr_Node;i--){
            Fill_Matrix[i][Start_Col]=Curr_Node->val;
            Curr_Node=Curr_Node->next;
        }
        Start_Col++;
    }

    return Fill_Matrix;

    }
};

int main() {

return 0;
}