 #include<iostream>
 #include<vector>
 #include<queue>
 
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

//BFS

void bfs(TreeNode* root){
    if(root==NULL){
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        int printill=q.size();

        for (int i=0;i<printill;i++){
            cout<<q.front()->val<<" ";

            if (q.front()->left!=NULL){
                q.push(q.front()->left);
            }
            if (q.front()->right!=NULL){
                q.push(q.front()->right);
            }

            q.pop();
            
        }
        cout<<endl;
    }
    
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

    // level Order Travarsal
    
    bfs(a);

     return 0;
 }