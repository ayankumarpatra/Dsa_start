#include<iostream>

/*
Q Create any basic tree you want then 
1. write a function to display the tree in any order
2. a function that returns the sum value of 
*/
using namespace std ;

class Node {
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val=val;
        left=right=NULL;
    }

};

void Display(Node* root){

    if (root==NULL){
        return;
    }

    cout<<root->val<<" ";

    Display(root->left);
    Display(root->right);
}

void SumHelper(Node*root , int &Sum){
    if(root==NULL){
        return;
    }

    Sum+=root->val;

    SumHelper(root->left,Sum);
    SumHelper(root->right,Sum);
}

int SumCalculator(Node*root){
    int sum=0;
    SumHelper(root,sum);
    return sum;
}

/*

sum func without helper 

int SumCalculator(Node* root){
    if(root == NULL) return 0;
    return root->val 
           + SumCalculator(root->left)
           + SumCalculator(root->right);
}


*/

int main (){

    Node*a =new Node(1);
    Node*b =new Node(2);
    Node*c =new Node(3);
    Node*d =new Node(4);
    Node*e =new Node(5);
    Node*f =new Node(6);
    Node*g =new Node(7);

    a->left=b;
    a->right=c;

    b->left=d;
    d->right=e;

    c->right=f;
    c->left=g;

    Display(a);

    cout<<"\nSum Will be : "<<SumCalculator(a);


    return 0;
}