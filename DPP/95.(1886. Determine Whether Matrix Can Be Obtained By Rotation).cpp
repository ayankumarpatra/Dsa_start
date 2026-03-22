#include<iostream>
#include<stack>
#include<vector>
 
using namespace std ;

class Solution {
public:
    void TransposeMAtrix(vector<vector<int>>& mat){
        int matlen=mat.size();

        for (int i=0;i<matlen;i++){
            for (int j=0;j<i;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }

        for (int i=0;i<matlen;i++){
            int start=0,end=matlen-1;
            
            while (start<end)
            {
                swap(mat[i][start],mat[i][end]);
                start++;
                end--;
            }           
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // we have to rotate4 times and check

        if (mat==target){
            return true;
        }
        
        for (int i=0 ;i<5;i++){
            TransposeMAtrix(target);

            if (mat==target){
                return true;
            }
        }
        return false;
    }
};


int main (){

    
    return 0;
}