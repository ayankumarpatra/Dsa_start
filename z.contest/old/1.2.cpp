#include<iostream>
#include<cmath>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int totaltime=0;
        int currflor=0;

        for (int i=0;i<requests.size();i++){
            while (currflor<=requests[i])
            {
                if (currflor==requests[i]){ break; }
                currflor++;
                totaltime++;
            }

            while (currflor>=requests[i])
            {
                if (currflor==requests[i]){ break; }
                currflor--;
                totaltime++;
            }
             
        }

        return totaltime;
    }
};




class Solution {
public:
    int minOperations(string s) {
        
        int n=s.size();

        int mincost=INT_MAX;

        for (int i=0;i<n;i++){
            int currcost=i;

            int maxlimit=n/2;

            for (int k=0;k<maxlimit;k++){
                int idx1= (i+k)%n;
                int idx2= (i+n-k-1)%n;

                int revcost= abs((s[idx1])-s[idx2]);

                int paircost =min(revcost , abs(26-revcost));
                currcost +=paircost;
            }

            mincost = min (mincost,currcost);
        }

        return mincost;
    }
};


int main (){

    
    return 0;
}