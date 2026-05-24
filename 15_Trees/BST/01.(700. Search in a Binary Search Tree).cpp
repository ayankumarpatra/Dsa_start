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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root==NULL){
            return NULL;
        }
        else if (root->val==val){
            return root;
        }
        else if (root->val>val){
            return searchBST(root->left,val);
        }
        else {
            return searchBST(root->right,val);
        }
    }
};


int main (){
 



    

     return 0;
 }