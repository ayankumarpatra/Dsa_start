#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left=0,right=0,dash=0;

        for(int i=0;i<moves.size();i++){
            if (moves[i]=='L'){
                left++;
            }
            else if (moves[i]=='R'){
                right++;
            }
            else{
                dash++;
            }
        }

        return max(left,right)+dash-min(left,right);
    }
};


int main (){

    
    return 0;
}