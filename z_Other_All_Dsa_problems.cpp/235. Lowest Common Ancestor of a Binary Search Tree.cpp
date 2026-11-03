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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int minval = min (p->val, q->val);
        int maxval = max (p->val , q->val);


        while ( root!= NULL )
        {
            // if the root value is greater , move to the left side of tree 
            
            if (root->val > maxval ){
                root = root->left;
            }
            
            // if the root value is smaller , move to the right side of tree 
            else if (root->val < minval ){
                root = root->right;
            }

            else{ // else its the lcm 
                return root; 
            }
        }
        
        return NULL;

    }
};
 
 
 int main (){
 
     
     return 0;
 }