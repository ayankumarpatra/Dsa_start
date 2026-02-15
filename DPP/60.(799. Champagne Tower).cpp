#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        // first row contains only one glass
        vector<double> previous_row(1, (double)poured);

        // build row by row until we reach query_row
        for (int current_row = 1; current_row <= query_row; current_row++) {

            // current row has current_row + 1 glasses
            vector<double> current_row_data(current_row + 1, 0.0);

            // go through all glasses of previous row
            for (int glass = 0; glass < current_row; glass++) {

                // calculate extra champagne (above 1 cup)
                double extra_amount = previous_row[glass] - 1.0;

                // if there is overflow
                if (extra_amount > 0.0) {

                    // divide equally to left and right glass
                    current_row_data[glass] += extra_amount * 0.5;
                    current_row_data[glass + 1] += extra_amount * 0.5;
                }
            }

            // move current row to previous_row for next iteration
            previous_row.swap(current_row_data);
        }

        // a glass can contain at most 1
        return min(1.0, previous_row[query_glass]);
    }
};



int main (){

    
    return 0;
}