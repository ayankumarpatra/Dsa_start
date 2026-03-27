#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    long long minNumberOfSeconds(int height, vector<int>& times) {

        long long left = 1;
        long long right = 10000000000000000LL; // large upper bound

        while (left < right) {

            long long mid_time = (left + right) >> 1;

            long long total_layers = 0;

            // check how many layers workers can build in mid_time
            for (int worker_time : times) {

                // if already enough layers, stop early
                if (total_layers >= height)
                    break;

                // calculate layers this worker can build
                long long layers =
                    (long long)(sqrt((2.0 * mid_time) / worker_time + 0.25) - 0.5);

                total_layers += layers;
            }

            // if workers can build enough layers, try smaller time
            if (total_layers >= height)
                right = mid_time;
            else
                left = mid_time + 1;
        }

        return left;
    }
};


int main (){

    
    return 0;
}