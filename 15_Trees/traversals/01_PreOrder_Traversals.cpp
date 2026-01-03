#include<iostream>


using namespace std ;

class node {
    public:
    int val;
    node*left;
    node*right;

    node (int val){
        this->val=val;
        left=right=NULL;
    }

};

void Display(node* root){
    if(root==NULL){
        return;
    }

    cout<<root->val<<" ,";

    Display(root->left);
    Display(root->right);
}


int main (){

    node*a=new node(1);
    node*b=new node(2);
    node*c=new node(3);

    a->left=b;
    b->right=c;
  



    Display(a);

    return 0;
}