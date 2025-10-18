/*

spiral matrix 

*/

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

    vector<vector<int>> Filled_Matrix(m,vector<int>(n,-1));

    int Start_Row=0,End_Row=m-1;
    int Start_Col=0,End_Col=n-1;

    while(head!=NULL){
        //left to right 
        for(int i=Start_Col;i<=End_Col && head!=NULL;i++){
            Filled_Matrix[Start_Row][i]=head->val;
            head=head->next;
        }
        Start_Row++;

        //right side up to down
        for(int i=Start_Row;i<=End_Row && head!=NULL;i++){
            Filled_Matrix[i][End_Col]=head->val;
            head=head->next;
        }
        End_Col--;

        // bottom right to left 
        for(int i=End_Col;i>=Start_Col && head!=NULL;i--){
            Filled_Matrix[End_Row][i]=head->val;
            head=head->next;
        }
        End_Row--;

        //left bottom to top
        for(int i=End_Row;i>=Start_Row && head!=NULL;i--){
            Filled_Matrix[i][Start_Col]=head->val;
            head=head->next;
        }
        Start_Col++;
        
    }
    return Filled_Matrix;
    }
};

int main() {

return 0;
}