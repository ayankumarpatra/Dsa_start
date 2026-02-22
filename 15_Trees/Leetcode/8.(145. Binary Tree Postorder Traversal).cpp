 #include<iostream>
 #include<vector>
 #include<stack>
 #include<algorithm>
 
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

        void helper(TreeNode*root , vector<int> & resultvector){
        // preorder means  left right root

        if (root==NULL){
            return;
        }

        // left;
        helper(root->left,resultvector);
        // right;
        helper(root->right,resultvector);
        //root
        resultvector.push_back(root->val);

    }

    vector<int> postorderTraversal(TreeNode* root) {
                vector<int> resultvector;

        helper(root,resultvector);

        return resultvector;
    }
};


// by iteration 

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> returnvector;
        stack<TreeNode*> st;
        TreeNode*currnode;

        if(root!=NULL){
            st.push(root);
        }

        while(st.size()>0){
            currnode=st.top();
            st.pop();

            returnvector.push_back(currnode->val);

            if (currnode->left!=NULL){
                st.push(currnode->left);
            }
            if (currnode->right!=NULL){
                st.push(currnode->right);
            }
        }
        reverse(returnvector.begin(),returnvector.end());
        return returnvector;
    }
};


 int main (){
 
     
     return 0;
 }