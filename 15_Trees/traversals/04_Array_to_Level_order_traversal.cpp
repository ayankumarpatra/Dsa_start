#include<iostream>
#include<queue>
#include<vector>
#include<climits>

using namespace std ;

// Given an array,create a tree , print out the level order travarsal of that , int min refers to null
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

TreeNode* treecreator(const vector<int> &array){

    if (array.size()==0){
        return NULL;
    }

    int i=0,maxlen=array.size();

    TreeNode * root=new TreeNode(array[i++]);
    TreeNode * tempnode;

    queue<TreeNode *> q;
    q.push(root);

    while (q.size()>0 && i<maxlen)
    {
        TreeNode * currroot=q.front();
        q.pop();

        if (i<maxlen && array[i]!=INT_MIN){
            currroot->left=new TreeNode(array[i]);
            q.push(currroot->left);
        }
        i++;
        if (i<maxlen && array[i]!=INT_MIN){
            currroot->right=new TreeNode(array[i]);
            q.push(currroot->right);
        }
        i++;
        
    }
    return root;

}

void BFS(TreeNode* root){
    if (root==NULL){
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        int maxprint=q.size();

        while (maxprint>0)
        {
            cout<<q.front()->val<<" ";

            if (q.front()->left!=NULL){
                q.push(q.front()->left);
            }
            if (q.front()->right!=NULL){
                q.push(q.front()->right);
            }

            q.pop();
            maxprint--;
        }

        cout<<endl;
      
    }
    
}

int main (){

    vector<int> vect={1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,INT_MIN,28,INT_MIN,INT_MIN};
    TreeNode * root;

    root=treecreator(vect);

    BFS(root);


    return 0;
}