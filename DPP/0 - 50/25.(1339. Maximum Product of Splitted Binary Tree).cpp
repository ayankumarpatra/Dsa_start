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
    long long totalSum = 0;
    long long maxProd = 0;
    int MOD = 1e9 + 7;

public:
    int maxProduct(TreeNode* root) {
        // Step 1: Find the total sum of the tree
        totalSum = calculateTotalSum(root);
        
        // Step 2: Find the subtree sum that maximizes the product
        findMaxProduct(root);
        
        return maxProd % MOD;
    }

    // Standard DFS to get the total sum
    int calculateTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + calculateTotalSum(root->left) + calculateTotalSum(root->right);
    }

    // Second DFS to find the best split
    int findMaxProduct(TreeNode* root) {
        if (!root) return 0;
        
        // Sum of the subtree rooted at 'root'
        int currentSubtreeSum = root->val + findMaxProduct(root->left) + findMaxProduct(root->right);
        
        // Calculate product if we cut the edge above this node
        long long product = (long long)currentSubtreeSum * (totalSum - currentSubtreeSum);
        maxProd = max(maxProd, product);
        
        return currentSubtreeSum;
    }
};
 
 int main (){
 
     
     return 0;
 }