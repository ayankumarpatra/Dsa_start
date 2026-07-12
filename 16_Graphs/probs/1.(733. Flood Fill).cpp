#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    void dfs (vector<vector<int>>& image, int CurrRow, int CurrCol, int initial_color, int updated_color){

        
        int RowMax=image.size();
        int ColMax=image[0].size();
        
        // first check if the curr pos eg x,y is inside the grid or not 
        if (CurrCol<0 || CurrRow<0 || CurrRow>= RowMax || CurrCol>= ColMax){
            return; // eg curr pos is outside of the iamge
        }
        // else if the curr row,col cell color is diff than initial color we cant move forward again
        if (image[CurrRow][CurrCol]!=initial_color){
            return;
        }
        // or also if both initial and final color is same , return 

        if (updated_color == initial_color){
            return;
        }

        // else all safee to go , only 4 calls with new color up , down , left , right 

        image[CurrRow][CurrCol]=updated_color; //updating curr color 

        dfs(image,CurrRow-1,CurrCol,initial_color,updated_color);//up
        dfs(image,CurrRow+1,CurrCol,initial_color,updated_color);//down
        dfs(image,CurrRow,CurrCol+1,initial_color,updated_color);//right
        dfs(image,CurrRow,CurrCol-1,initial_color,updated_color);// left
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs (image,sr,sc,image[sr][sc],color);
        return image;
    }
};


int main (){

    
    return 0;
}