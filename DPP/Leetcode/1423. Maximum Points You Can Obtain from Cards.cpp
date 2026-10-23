#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int window =0;
 
        for (int i=0;i<k;i++){
            window += cardPoints[i];
        }

        int maxwindow =window;

        int front=k-1,back=cardPoints.size()-1;

        for (int i=k;i>0;i--)
        {
            // removing last element
            window -= cardPoints[front--];
            // adding the next valid index 
            window += cardPoints[back--];

            maxwindow = max (window,maxwindow);
        }
        
        return maxwindow;
    }
};


int main (){

    
    return 0;
}