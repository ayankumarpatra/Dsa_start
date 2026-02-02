 #include<iostream>
 #include<climits>
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

    construct tree fro level order travarsal
    */
 
void treecreator(const vector<int> &array){// note i am defyning null as int_min as only -1 maybe a possible value 

    // if array size is 0  theres no tree;

    if (array.size()==0){
        return ;// returning nothing 
    }

    // now tree will have some values;

    int i=0,maxlen=array.size();

    TreeNode * root=new TreeNode(array[i++]);
    TreeNode * tempnode;

    queue<TreeNode *> q;
    q.push(root);

    while (q.size()>0 && i<maxlen)
    {
        TreeNode * currroot=q.front();
        q.pop();

        if (i<maxlen && array[i]!=INT_MIN){
            currroot->left=new TreeNode(array[i]);
            q.push(currroot->left);
        }
        i++;
        if (i<maxlen && array[i]!=INT_MIN){
            currroot->right=new TreeNode(array[i]);
            q.push(currroot->right);
        }
        i++;
        
    }
    

}

 
 int main (){
 
    vector<int> mainarr={1,2,3,4,NULL,5};
     
     return 0;
 }