#include<iostream>
#include<climits>
#include<vector>

using namespace std ;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int neg_count = 0;
        int Minval = INT_MAX;

        for (auto &row : matrix) {
            for (int val : row) {
                if (val < 0) neg_count++;

                sum += abs(val);
                Minval = min(Minval, abs(val));
            }
        }

        // if odd number of negatives, one must stay negative
        if (neg_count % 2 == 1) {
            sum -= 2 * Minval;
        }

        return sum;
    }
};



int main (){

    
    return 0;
}