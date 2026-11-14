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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> returnvect;
        if (root==NULL){
            return returnvect;
        }

        queue<TreeNode*> q ;
        q.push(root);

        while (!q.empty() )
        {
            int n = q.size();
            // pop n-1 elelemnts , last one will be the required node 
            for (int i =0 ;i <n-1 ; i++){

                if (q.front()->left != NULL){
                    q.push(q.front()->left);
                }

                if (q.front()->right != NULL){
                    q.push(q.front()->right);
                }

                q.pop();
            }

            // add the last remaining node to queue 
            returnvect.push_back( q.front()->val );

                if (q.front()->left != NULL){
                    q.push(q.front()->left);
                }

                if (q.front()->right != NULL){
                    q.push(q.front()->right);
                }

            q.pop();
        }
        

        return returnvect;
    }
};



 int main (){
 
     
     return 0;
 }