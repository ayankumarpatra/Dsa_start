#include<iostream>
#include<climits>

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

int MinValInTree(Node* root){
    if (root==NULL){
        return INT_MAX;
    }

    int leftmin=MinValInTree(root->left);
    int rightmin=MinValInTree(root->right);

    return min(root->val,min(leftmin,rightmin));
}


int main (){

    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(-3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);

    a->left=b;
    a->right=c;

    b->left=d;
    d->right=e;

    c->right=f;
    c->left=g;

    cout<<"Min value will be : "<<MinValInTree(a);

    
    return 0;
}