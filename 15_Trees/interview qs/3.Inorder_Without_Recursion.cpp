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
 
 
// left root right

/*
1. an empty stack st 
2. maintain a node treenode , initialize it by root
3. iterate by left side {
                if (node!=NULL){
                    st.push(node);
                }
                    node=node->left;
}

4.  if the node become null go to right side then {
                // after the prev if code 

                else {
                if (node!=null){
                temp=st.top();
                st.pop();
                // print or push back in vector
                node=temp->right;
                }
                }
}

*/


 int main (){
 
     
     return 0;
 }