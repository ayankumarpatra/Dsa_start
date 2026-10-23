#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        sort(cost.begin(),cost.end(),greater<int>());

        int mincost=0,count=0;

        for (int i=0;i<cost.size();i++){
            if (count==2) {
                count=0;
                continue;
            }
            else{
                mincost+=cost[i];
                count++;
            }
        }
        return mincost;
    }
};


int main (){

    
    return 0;
}