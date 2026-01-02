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
    bool NodeExists(TreeNode* root , TreeNode* target){
        if (root==NULL){
            return false;
        }
        if (root==target){
            return true;
        }

        return NodeExists(root->left,target) || NodeExists(root->right,target);
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        actually 3 cases can happen 
        1. both node at left side 
        2. both node at right side 
        3. else for an condition like 1 left or 1 right or both originate from same node , the root is the ans 
        */
        // case 1 both node reside at left side 

        if (NodeExists(root->left,p) && NodeExists(root->left,q)){
            return lowestCommonAncestor(root->left,p,q);
        }

        if (NodeExists(root->right,p) && NodeExists(root->right,q)){
            return lowestCommonAncestor(root->right,p,q);
        }

        return root;

    }
};
 
 
int main (){
 
     
     return 0;
 }