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
    void helper(TreeNode*root , vector<int> & resultvector){
        // inorder means left root right

        if (root==NULL){
            return;
        }

        // left;
        helper(root->left,resultvector);
        // root
        resultvector.push_back(root->val);
        // right;
        helper(root->right,resultvector);

    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> resultvector;

        helper(root,resultvector);

        return resultvector;        
    }
};
 
 int main (){
 
     
     return 0;
 }