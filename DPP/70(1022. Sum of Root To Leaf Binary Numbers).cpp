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
        this->left=left;
        this->right=right;
    }

};
 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int dfs(TreeNode* root,int number){
    if(!root) return 0;
    number=root->val+number*2;
    if(!root->left&&!root->right){
        return number;
    }
    return dfs(root->left,number)+dfs(root->right,number);
}
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root,0);
    }
};
 
 int main (){
 
     
     return 0;
 }