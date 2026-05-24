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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* addnode=new TreeNode(val);

        if(root==NULL){
            return addnode;
        }

        TreeNode* front_node=root;
        TreeNode* back_node;

        while (front_node!=NULL)
        {
            back_node=front_node;
            if(front_node->val>val){
                front_node=front_node->left;
            }
            else{
                front_node=front_node->right;
            }
        }


        if (back_node->val>val){
            back_node->left=addnode;
        }
        else{
            back_node->right=addnode;
        }

        return root;
        
    }
};



int main (){
 
     
     return 0;
 }