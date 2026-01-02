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

    void PathHelper(TreeNode* root,string s, vector<string>& ans){
        // leaf node means left right both null 

        if (root==NULL){
            return;
        }

        if(root->left==NULL && root->right==NULL){
            s=s+to_string(root->val);
            ans.push_back(s);
            return;
        }

        PathHelper(root->left,s+to_string(root->val)+"->",ans);

        PathHelper(root->right,s+to_string(root->val)+"->",ans);

    }


    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> str;
        
        PathHelper(root,"",str);

        return str;
    }
};
 
 int main (){
 
     
     return 0;
 }