#include<iostream>

using namespace std ;

class node {
    public :
    int val;
    node* left;
    node* right;

    node(int val){
        this->val=val;
        left=right=NULL;
    }
};


void inorder(const node *root){
    if (root==NULL){
        return;
    }

    // inorder as the func is being called at mid  
    // so like here left root right
    // ip 4 2 5 1 6 3 7

    // give straight lines and then draw as per the need and write from left to right 
    
    inorder(root->left);

    cout<<root->val<<" ";
    
    inorder(root->right);

}


int main (){

    node* a=new node(1);
    node* b=new node(2);
    node* c=new node(3);
    node* d=new node(4);
    node* e=new node(5);
    node* f=new node(6);
    node* g=new node(7);

    a->left=b;
    a->right=c;

    b->left=d;
    b->right=e;

    c->left=f;
    c->right=g;

    inorder(a);

    return 0;
}