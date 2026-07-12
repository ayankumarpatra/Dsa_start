#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        if (edges.size()==0){
            return 0;
        }

        int node1 = edges[0][0],node2= edges[0][1];

        for (int i=1;i<edges.size();i++){
            if (edges[i][0]== node1){
                return node1;
            }
            if (edges[i][0]== node2){
                return node2;
            }
            if (edges[i][1]== node1){
                return node1;
            }
            if (edges[i][1]== node2){
                return node2;
            }
        }

        return 0;
    }
};


int main (){

    
    return 0;
}