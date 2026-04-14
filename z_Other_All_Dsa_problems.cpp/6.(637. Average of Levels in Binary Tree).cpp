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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> return_val;

        queue<TreeNode*> q;

        q.push(root);

        while (q.size()>0)
        {
            int currlen=q.size();
            double clen=currlen;
            double val=0.0;

            while (currlen>0)
            {
                if(q.front()->left!=NULL){
                    q.push(q.front()->left);
                }

                if(q.front()->right!=NULL){
                    q.push(q.front()->right);
                }

                val+=q.front()->val;
                q.pop();
                currlen--;
            }
            val=val/clen;
            return_val.push_back(val);
        }
        return return_val;
    }
};

 int main (){
 
     
     return 0;
 }