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
 
void treecreator(const vector<int> &array){// note i am defyning null as int_min as only -1 maybe a possible value 

    // if array size is 0  theres no tree;

    if (array.size()==0){
        return ;// returning nothing 
    }

    // now tree having some values 

    TreeNode* tempnode=new TreeNode(array[0]);
    TreeNode *root=tempnode; 

}

 
 int main (){
 
    vector<int> mainarr={1,2,3,4,NULL,5};
     
     return 0;
 }