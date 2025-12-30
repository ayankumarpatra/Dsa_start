#include<iostream>

using namespace std ;

class Node {
    public :
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val=val;
        left=right=NULL;
    }
};

int Tree_Level_Finder(Node * root){
    if (root==NULL){
        return 0;
    }

    return (1+max(Tree_Level_Finder(root->left),Tree_Level_Finder(root->right)));
}


int main (){

    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);

    a->left=b;
    a->right=c;

    b->left=d;
    b->right=e;

    c->left=f;
    c->right=g;

// Height = level-1
    cout<<"Tree Level is "<<Tree_Level_Finder(a);
    return 0;
}