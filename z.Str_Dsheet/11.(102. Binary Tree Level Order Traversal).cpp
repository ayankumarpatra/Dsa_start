 #include<iostream>
 #include<vector>
 #include<queue>
 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> returnvect;
        queue<TreeNode*> q;

        if (root==NULL){
            return returnvect;
        }

        q.push(root);

        while (q.size()>0)
        {
            int len=q.size();
            vector<int> tempvector;

            while (len>0)
            {
                tempvector.push_back(q.front()->val);
                if(q.front()->left!=NULL){
                    q.push(q.front()->left);
                }
                if(q.front()->right!=NULL){
                    q.push(q.front()->right);
                }
                q.pop();
                len--;
            }
            returnvect.push_back(tempvector);
            
        }
        return returnvect;
    }
};

 int main (){
 
     
     return 0;
 }