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
    int TreeLevel(TreeNode* root){
        if (root==NULL){
            return 0;
        }

        return (1+ max(TreeLevel(root->left), TreeLevel(root->right)));
    }

    void DiaHelper(TreeNode* root, int &maxdia){
        if (root==NULL){
            return;
        }
        int dia= TreeLevel(root->left)+TreeLevel(root->right);

        maxdia=max(maxdia,dia);

        DiaHelper(root->left,maxdia);
        DiaHelper(root->right,maxdia);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int MaxDia=0;
        DiaHelper(root,MaxDia);
        return MaxDia;
    }
};
 
 
 int main (){
 
     
     return 0;
 }