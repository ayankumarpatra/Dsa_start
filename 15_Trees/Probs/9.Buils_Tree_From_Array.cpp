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

    
    /*
    
    you will be given a array like {1,2,3,4,NULL}
   
    TREE will be like 1 left 2 , right 3, 2s left 4 rest all NULL
    */
 
void treecreator(const vector<int> &array){
    int size=array.size();

    if (size<=0){
        return;
    }

    int currlevel=0,currindex=0,maxindex=array.size();

    TreeNode * tempnode=new TreeNode(array[currindex]);

    currindex++;
    
    TreeNode* root=tempnode;
    
    // as binary tree so no of nodes in each level= 2^level
    
    queue<int> q;
    
    q.push(array[currindex]);
    currindex++;
    q.push(array[currindex]);
    currindex++;

    while (currindex<maxindex)
    {
        while (q.front()==NULL){
            q.pop();
        }
        els
    }
    
}

 
 int main (){
 
    vector<int> mainarr={1,2,3,4,NULL,5};
     
     return 0;
 }