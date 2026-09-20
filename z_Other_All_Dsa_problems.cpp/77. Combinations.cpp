#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:

    void helper (int start , int&n, int k , vector<int>&temp , vector<vector<int>> &returnvect){
        if (k==0){
            returnvect.push_back(temp);
            return;
        }

        if (start>n){
            return;
        }

        if (n - start + 1 < k){ //purning
            //If I need k numbers but there aren't even k numbers left, stop immediately.
            return;
        }

        // taking start and moving towards next
        temp.push_back(start);
        helper(start+1,n,k-1,temp,returnvect);

        // skipping the start and keep building next
        temp.pop_back();
        helper(start+1,n,k,temp,returnvect);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> returnvect;

        vector<int> temp;

        helper(1,n,k,temp,returnvect);

        return returnvect;
    }
};


int main (){

    
    return 0;
}