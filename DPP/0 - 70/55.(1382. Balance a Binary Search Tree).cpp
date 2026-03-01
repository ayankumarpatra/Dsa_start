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

    void Fill_Elements(vector<int>& mainvector,TreeNode* root){
        if (root==NULL){
            return;
        }

        Fill_Elements(mainvector,root->left);
        mainvector.push_back(root->val);// fixed , inorder travarse to get sorted array
        Fill_Elements(mainvector,root->right);
    }

    TreeNode* Treecreator(int left,int right , vector<int> & mainvector){
        if (left>right){
            return NULL;
        }
        int mid = (left+right)/2;

        TreeNode* root= new TreeNode(mainvector[mid]);

        root->left=Treecreator(left,mid-1,mainvector);
        root->right=Treecreator(mid+1,right,mainvector);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        if (root==NULL){
            return NULL;
        }
        vector<int> mainvector;
        Fill_Elements(mainvector,root);


        
        return Treecreator(0,mainvector.size()-1,mainvector);
    }
};


 int main (){
 
     
     return 0;
 }