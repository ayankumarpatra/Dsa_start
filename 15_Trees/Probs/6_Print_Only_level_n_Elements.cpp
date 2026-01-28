 #include<iostream>
 #include<vector>
 
 using namespace std ;
 
class Node {
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val=0,Node* left=NULL,Node* right=NULL){
        this->val=val;
        this->left=left;
        this->right=right;
    }

};
 
 
void printLeveln(Node* root, int leveltoprint,int currlevel=1){// thinking root is the level 1
    if (root==NULL || currlevel>leveltoprint){
        return;
    }

    if (leveltoprint==currlevel){
        cout<<root->val<<", ";
        return;
    }

    // left
    printLeveln(root->left,leveltoprint,currlevel+1);
    // right
    printLeveln(root->right,leveltoprint,currlevel+1);
}
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
    b->right=e;

    c->left=f;
    c->right=g;

    printLeveln(a,3);
     return 0;
 }