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

    void PathHelper(TreeNode* root,string s, vector<string> str){
        // leaf node means left right both null 

        if(root->left==NULL && root->right==NULL){
            return;
        }

        str.push_back(char(root->val));


    }


    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> str;
        
        
    }
};
 
 int main (){
 
     
     return 0;
 }