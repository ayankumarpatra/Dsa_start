#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:

    void helper (int start, int &n, int k , vector<int> temp , vector<vector<int>> &returnvect) {
        if (k==0){
            returnvect.push_back(temp);
            return;
        }

        if (start>n){
            return;
        }

        // taking current element
        temp.push_back(start);
        helper(start+1,n,k-1,temp,returnvect);

        // excluding start , thinking other possibilities 
        temp.pop_back();
        helper(start+1,n,k,temp,returnvect);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> returnvect;

        helper(1,n,k,temp,returnvect);
    }
};

int main (){

    
    return 0;
}