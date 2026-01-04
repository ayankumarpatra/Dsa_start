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


void Postorder(const node *root){
    if (root==NULL){
        return;
    }

    // Postorder as the func is being called at last  
    // so like here left root right
    // ip 4 2 5 1 6 3 7

    // give straight lines and then draw as per the need and write from left to right 
    
    Postorder(root->left);
 
    Postorder(root->right);
    
    cout<<root->val<<" ";

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

    Postorder(a);

    return 0;
}