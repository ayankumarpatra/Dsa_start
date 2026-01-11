 #include<iostream>
 #include<vector>
 
 using namespace std ;
 
class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val=0,TreeNode* left=NULL,TreeNode* right=NULL){
        this->val=val;
        this->left==left;
        this->right=right;
    }

};
 
void preoder(TreeNode* root){
    if (root==NULL){
        return;
    }

    cout<<root->val<<" ";// preorder
    preoder(root->left);
    preoder(root->right);
}

void inoder(TreeNode* root){
    if (root==NULL){
        return;
    }

    inoder(root->left);
    cout<<root->val<<" ";
    inoder(root->right);
}

void postoder(TreeNode* root){
    if (root==NULL){
        return;
    }

    postoder(root->left);
    postoder(root->right);
    cout<<root->val<<" ";
}
 
 int main (){

    TreeNode* a= new TreeNode(1);
    TreeNode* b= new TreeNode(2);
    TreeNode* c= new TreeNode(3);
    TreeNode* d= new TreeNode(4);
    TreeNode* e= new TreeNode(5);
    TreeNode* f= new TreeNode(6);
    TreeNode* g= new TreeNode(7);
    TreeNode* h= new TreeNode(8);
    TreeNode* i= new TreeNode(9);
    TreeNode* j= new TreeNode(10);
    TreeNode* k= new TreeNode(11);
 
    a->left=b;
    b->left=d;
    d->left=h;
    b->right=e;
    e->left=i;
    e->right=j;

    a->right=c;
    c->left=f;
    f->right=k;
    c->right=g;

    preoder(a);

     return 0;
 }