#include<iostream>
#include<cmath>
#include<climits>
#include<bitset>

using namespace std ;
class Solution {
public:
    int binaryGap(int n) {
        int max_gap = 0;
        int last_position = -1;
        int current_position = 0;

        while (n > 0) {

            if (n & 1) {
                if (last_position != -1) {
                    max_gap = max(max_gap, current_position - last_position);
                }
                last_position = current_position;
            }
            
            n >>= 1;
            current_position++;
        }

        return max_gap;
    }
};


int main (){

    
    return 0;
}