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
 
int absheight(TreeNode* root){
    if ( root== NULL){
        return 0;
    }

    // check left 
    int left = absheight(root->left);
    if (left==-1){
        return -1;
    }
    
    
    // check right 
    int right = absheight(root->right);
    if (right==-1){
        return -1;
    }

    if (abs(left-right)>1){
        return -1;
    }

    return (1+max(left,right));
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {

        return absheight(root)!=-1;
    }
}; 
 int main (){
 
     
     return 0;
 }