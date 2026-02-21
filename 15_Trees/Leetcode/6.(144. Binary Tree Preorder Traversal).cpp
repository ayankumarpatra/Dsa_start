 #include<iostream>
 #include<vector>
 #include<stack>
 
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
        // preorder means root left right

        if (root==NULL){
            return;
        }

        resultvector.push_back(root->val);
        // left;
        helper(root->left,resultvector);
        // right;
        helper(root->right,resultvector);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> resultvector;

        helper(root,resultvector);

        return resultvector;
    }
};
 

// travarse by iteration 


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> returnvector;

        if (root==NULL){
            return returnvector;
        }


        stack<TreeNode*> st;

        st.push(root);
        TreeNode* temp;

        while(!st.empty()){
            temp=st.top();
            st.pop();

            returnvector.push_back(temp->val);

            if (temp->right!=NULL){
                st.push(temp->right);
            }
            if (temp->left!=NULL){
                st.push(temp->left);
            }
        }

        return returnvector;
        
    }
};
 int main (){
 
     
     return 0;
 }