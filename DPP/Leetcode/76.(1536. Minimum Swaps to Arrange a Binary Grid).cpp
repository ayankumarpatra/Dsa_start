#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> temp;
        
        
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = n - 1; j >= 0; j--){
                if(grid[i][j] == 1) break;
                count++;
            }
            temp.push_back(count);
        }

        int result = 0;

        
        for(int i = 0; i < n; i++){
            int required = n - i - 1;
            int j = i;

            while(j < n && temp[j] < required){
                j++;
            }

            if(j == n) return -1; 

            
            while(j > i){
                swap(temp[j], temp[j - 1]);
                result++;
                j--;
            }
        }

        return result;
    }
};


int main (){

    
    return 0;
}