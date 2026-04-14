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
 
class Solution {
public:
    void pret(TreeNode* root, vector<int>&v){
        if (root==NULL){
            return;
        }
        v.push_back(root->val);
        pret(root->left,v);
        pret(root->right,v);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> mainvector;

        pret(root,mainvector);
        return mainvector;
    }
};
 
 int main (){
 
     
     return 0;
 }