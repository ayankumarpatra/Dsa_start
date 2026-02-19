/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
 
// taking INT_MIN to define null as in array we cant define it 
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Standard TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* TreeCreator(const vector<int>& mainvector) {

    if(mainvector.empty()||mainvector[0]==INT_MIN){
        return NULL;
    }

    else if (mainvector.size()==1){
        return new TreeNode(mainvector[0]);
    }


    TreeNode* root=new TreeNode(mainvector[0]);

    queue<TreeNode*> q;

    q.push(root);
    int maxlen=mainvector.size(),i=1;

    while (q.size()>0 && i<maxlen){
        TreeNode* currhead=q.front();
        q.pop();

        // adding left 
        if (i<maxlen && mainvector[i]!=INT_MIN){
            TreeNode* tempnode=new TreeNode(mainvector[i]);
            currhead->left=tempnode;
            q.push(tempnode);
        }
        i++;
        // adding right
        if (i<maxlen && mainvector[i]!=INT_MIN){
            TreeNode* tempnode=new TreeNode(mainvector[i]);
            currhead->right=tempnode;
            q.push(tempnode);
        }
        i++;
    }

    return root;
}


 int main (){
 
     
     return 0;
 }