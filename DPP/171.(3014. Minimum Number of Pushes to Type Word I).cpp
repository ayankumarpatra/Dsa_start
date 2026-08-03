#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int minimumPushes(string word) {
        int count=0;
        unordered_map<int,int>um;

        int st=2;
        for(char &ch:word){
            if(st>9){
                st=2;
            }
            um[st]++;
            count+=um[st];
            st++;
        }
        return count;
    }
};


int main (){

    
    return 0;
}