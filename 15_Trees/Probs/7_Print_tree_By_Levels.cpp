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
 
/*
next q print a tree by levels 
eg if       root a , a->beft b , right=c

print 

a
bc
...  cont ...

note :
maxlevel will not be given
*/


// as level will not given , no problem will claculate

int treelevel_finder(Node *root){
    if (root==NULL){
        return 0;
    }

    return (1+max(treelevel_finder(root->left),treelevel_finder(root->right)));
}

void printLeveln(Node* root, int leveltoprint,int currlevel=1){// old func no modify
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

void treeprinter(Node* root){
    int maxlevel=treelevel_finder(root);

    for(int i=1;i<=maxlevel;i++){
        printLeveln(root,i);
        cout<<endl;
    }
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

    treeprinter(a);
     return 0;
 }