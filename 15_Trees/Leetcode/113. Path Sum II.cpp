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
    void helper ( TreeNode* root,  vector<vector<int>> & returnvect , vector<int> temp , int currsum , int target){
        if (root==NULL){ return; }

        currsum+= root->val;
        temp.push_back(root->val);

        // if its leaf node and sum is target add path 

        if (root->left==NULL && root->right==NULL && currsum==target){
            returnvect.push_back(temp);
        }

        helper ( root->left , returnvect , temp , currsum , target);
        helper ( root->right , returnvect , temp , currsum , target);

        temp.pop_back();

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> returnvect;
        vector<int> temp;

        helper (root,returnvect,temp,0,targetSum );

        return returnvect;
    }
};
 
 int main (){
 
     
     return 0;
 }