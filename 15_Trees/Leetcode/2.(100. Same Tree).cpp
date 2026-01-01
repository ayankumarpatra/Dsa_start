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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // check if both null , true then
        if (p==NULL && q==NULL){
            return true;
        }
        // check if any one of them of them are null
        if (p==NULL || q==NULL){
            return false;
        }

        // check of val diff 
        if (p->val!=q->val){
            return false;
        }

        // recursive call both sides 
        // warning no need to return true if val same ; as we have to recursively check till the longest path

        return ( isSameTree (p->left , q->left) && isSameTree (p->right , q->right ));


    }
};
 
 int main (){
 
     
     return 0;
 }