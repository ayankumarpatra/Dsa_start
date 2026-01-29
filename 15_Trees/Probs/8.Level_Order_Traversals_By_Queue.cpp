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

        queue<TreeNode*> q;

        vector<vector<int>> ansvector;

        if (root==NULL){
            return ansvector;
        }

        q.push(root);

        while (!q.empty()){

            int currlen=q.size();
            vector<int> levelvector;

            for (int i=0;i<currlen;i++){
                // push backing front value
                levelvector.push_back(q.front()->val);
                // checking if left and right of that is null or not , so push back the nodes then if not null

                if(q.front()->left!=NULL){
                    q.push(q.front()->left);
                }
                if(q.front()->right!=NULL){
                    q.push(q.front()->right);
                }
                // poping the curr front 
                q.pop();
                // push back current temp level factor
            }
            ansvector.push_back(levelvector);
        }
        return ansvector;
    }
};
 
 
 int main (){
 
     
     return 0;
 }