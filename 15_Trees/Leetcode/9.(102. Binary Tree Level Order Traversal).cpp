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

    int treedepthfinder(TreeNode* root){
        if (root==NULL){
            return 0;
        }

        return (1+max(treedepthfinder(root->left),treedepthfinder(root->right)));

    }

    void TreeLevel_Filler(TreeNode* root , vector<int>& mainvector, int level, int currlevel=1){// thinking root =1 level
        if (root==NULL || currlevel>level){
            return;
        }

        if (currlevel==level){
            mainvector.push_back(root->val);
            return ;
        }
        TreeLevel_Filler(root->left,mainvector,level,currlevel+1);
        TreeLevel_Filler(root->right,mainvector,level,currlevel+1);
    }


    vector<vector<int>> levelOrder(TreeNode* root) {
        int maxlevel=treedepthfinder(root);

        vector<vector<int>> mainvector;
        
        for (int i=1;i<=maxlevel;i++){
            vector<int> returnvector;
            TreeLevel_Filler(root,returnvector,i);
            mainvector.push_back(returnvector);
        }

        return mainvector;
    }
};
 
 int main (){
 
     
     return 0;
 }