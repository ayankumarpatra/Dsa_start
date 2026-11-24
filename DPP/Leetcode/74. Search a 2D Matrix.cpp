#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (! matrix.size()){ // if matrix size 0 
            return false;
        }

        int rowsize = matrix[0].size() -1 ;

        int i = -1;

        // outer loop to get the row 

        int low_out =0 , high_out = matrix.size() -1 , mid_out;

        while (low_out <= high_out)
        {
            mid_out = low_out + (high_out - low_out ) /2;

            if (matrix[mid_out][0] <= target && matrix[mid_out][rowsize] >= target){
                i=mid_out;
                break;
            }

            else if ( matrix[mid_out][rowsize] < target) {
                low_out = mid_out +1;
            }

            else{
                high_out = mid_out -1;
            }
        }

        // if i still -1 , means it doesnt there in the matrix 

        if (i==-1){
            return false;
        }
        
        // we get i as the main row 
            
        int low = 0 , high =rowsize , mid;

                while (low<=high)
                {
                    mid = low + (high-low)/2;

                    if (matrix[i][mid] == target){ // equal 
                        return true;
                    }
                    else if (matrix[i][mid] > target){ // less
                        high = mid -1 ;
                    }
                    else { // greater
                        low = mid + 1 ;
                    }
                }

        return false;
    }
};




int main (){

    
    return 0;
}