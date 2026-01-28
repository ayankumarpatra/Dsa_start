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
        // preorder means root left right

        if (root==NULL){
            return;
        }

        resultvector.push_back(root->val);
        // left;
        helper(root->left,resultvector);
        // right;
        helper(root->right,resultvector);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> resultvector;

        helper(root,resultvector);

        return resultvector;
    }
};
 
 int main (){
 
     
     return 0;
 }