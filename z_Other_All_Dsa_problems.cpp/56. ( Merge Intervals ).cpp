#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:

    // static bool comparator (const vector<int>&a, const vector<int>&b){
    //     return a[0]<b[0];
    // }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort (intervals.begin(),intervals.end());
        // cpp by default checks the element 0 , else we have to check by comparator  

        vector<vector<int>> returnvect;

        int first=0,end=0;

        for (int i=0;i<intervals.size();i++){

            first=intervals[i][0];
            end=intervals[i][1];

            i++;

            while ( i<intervals.size() && intervals[i][0]<=end )
            {
                end = max(end, intervals[i][1]);
                i++;
            }

            i--;

            returnvect.push_back ( {first,end} );
        }

        return returnvect;
    }
};



int main (){

    
    return 0;
}