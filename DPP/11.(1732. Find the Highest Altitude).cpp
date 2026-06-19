#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currheight=0;
        int maxgain=0; // as biker starts his trip on point 0 with altitude equal 0.

        for (int i=0;i<gain.size();i++){
            currheight+=gain[i];
            if (currheight>maxgain){
                maxgain=currheight;
            }
        }
        return maxgain;
    }
};


int main (){

    
    return 0;
}