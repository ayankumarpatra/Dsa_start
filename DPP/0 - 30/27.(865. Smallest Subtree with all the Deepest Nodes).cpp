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
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root)
            return {nullptr, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // if both sides have same depth
        if (left.second == right.second) {
            return {root, left.second + 1};
        }
        // left deeper
        else if (left.second > right.second) {
            return {left.first, left.second + 1};
        }
        // right deeper
        else {
            return {right.first, right.second + 1};
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};


 int main (){
 
     
     return 0;
 }