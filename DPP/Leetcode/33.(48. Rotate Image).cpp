#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        for (int i=0;i<matrix.size();i++){
            for (int j=i+1;j<matrix[0].size();j++){
                swap(matrix[j][i],matrix[i][j]);// dont do from i , else you will swipe twice so 
                //finally thing become the same 
            }
        }

        for (int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};



int main (){

    
    return 0;
}