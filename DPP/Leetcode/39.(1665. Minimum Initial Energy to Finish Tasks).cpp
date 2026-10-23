#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        
        // sorting the vector according to the min requirement

        sort(tasks.begin(),tasks.end(),[](const vector<int> &a , const vector<int> &b ){
                                            return (a[1]-a[0]) > (b[1]-b[0]);
                                        });
                                        
        int effortcount=0;// last element will have max need to start

        int curr_effort=effortcount;

        for (int i=0;i<tasks.size();i++){
            vector<int> currvector=tasks[i];
            int currneed=currvector[1];

            if (currneed<=curr_effort){// curr level have less than or equal to the curreffort
                curr_effort-=currvector[0];
            }
            else{
                int need=currneed-curr_effort;
                curr_effort+=need;
                effortcount+=need;

                curr_effort-=currvector[0];
            }
        }

        return effortcount;
    }
};


int main (){

    
    return 0;
}