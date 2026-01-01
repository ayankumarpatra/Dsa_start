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
 

class Solution {
public:
    void InvertHelper(TreeNode*root){
        if (root==NULL){
            return;
        }

        TreeNode * lefttemp=root->left;

        root->left=root->right;

        root->right=lefttemp;

        return InvertHelper(root->left);
        return InvertHelper(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        InvertHelper(root);
        return root;
    }
};
 
 int main (){
 
     
     return 0;
 }