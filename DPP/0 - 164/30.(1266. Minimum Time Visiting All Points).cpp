#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        //max length will be the olute value of the x and y distance 

        int maxd=0;

        for (int i=0;i<points.size()-1;i++){

                /*
                intension like 3 point given [[1,1],[3,4],[-1,0]]

                then first check for first pair [1,1],[3,4] then check for this [3,4],[-1,0] and continue addition 
                */

                maxd+=max ( abs((points[i][0])-(points[i+1][0])), abs((points[i][1])-(points[i+1][1])) );


        }

        return maxd;
    }
};


int main (){

    
    return 0;
}