#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std ;

// class Solution {
// public:
//     vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
//         int i=0;
//         vector<vector<int>> returnvector;

//         if (grid[0].size()<k){
//             vector<int> tempvector={0};
//             returnvector.push_back(tempvector);
//             return returnvector;// if matrix have elements less than grid return 0
//         }
//         while (1)
//         {
//             if (grid[0].size()<=k+i){
//                 break;
//             }
//             vector<int> tempvector;

//             for(i;i<k;i++){
//                 for (int j=0;j<k;j++){
//                     tempvector.push_back(grid[i][j]);// filling with all the elements
//                 }
//             }

//             sort(tempvector.begin(),tempvector.end());// these 2 lines same as set , but a little faster 
//             tempvector.erase(unique(tempvector.begin(),tempvector.end()),tempvector.end());

//             vector<int> addvector;
//             if (tempvector.size()==1){
//                 addvector.push_back(0);
//                 returnvector.push_back(addvector);
//                 continue;// given for saftey , however if else loop should work 
//             }

//             else {
//                 int min=INT_MAX;
//                 for (int i=0;i<tempvector.size()-1;i++){
//                     int curr_diff=abs(tempvector[i+1]-tempvector[i]);

//                     if (curr_diff<min){
//                         min=curr_diff;
//                     }
//                 }
//                 addvector.push_back(min);
//                 returnvector.push_back(addvector);
//             }

//         }
//            return returnvector;
//     }
    
// };


class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> result;

        for (int row = 0; row <= n - k; row++) {       // slide down
            vector<int> resultRow;

            for (int col = 0; col <= m - k; col++) {   // slide right
                
                // 1 collect all k*k elements
                vector<int> temp;
                for (int i = 0; i < k; i++) {
                    for (int j = 0; j < k; j++) {
                        temp.push_back(grid[row + i][col + j]);
                    }
                }

                // Step 2 sort + deduplicate
                sort(temp.begin(), temp.end());
                temp.erase(unique(temp.begin(), temp.end()), temp.end());

                // Step 3 find min diff
                if (temp.size() == 1) {
                    resultRow.push_back(0);
                } else {
                    int minDiff = INT_MAX;
                    for (int i = 0; i < (int)temp.size() - 1; i++) {
                        minDiff = min(minDiff, temp[i+1] - temp[i]);
                        // no need for abs() since array is sorted
                    }
                    resultRow.push_back(minDiff);
                }
            }
            result.push_back(resultRow);  // push one full row at a time
        }

        return result;
    }
};

int main (){

    
    return 0;
}