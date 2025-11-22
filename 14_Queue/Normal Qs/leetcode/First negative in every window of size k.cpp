#include<iostream>
#include<deque>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> shortestSubarray(vector<int>& v, int k) {

    vector<int> returnvector;

    if(v.size()<k){
        return returnvector;
    }

    deque<int> dq;

    for(int i=0;i<v.size();i++){
        if (v[i]<0){
            dq.push_back(v[i]);
        }

        if((i+1)%k==0){
            if(dq.size()>0){
                returnvector.push_back(dq.front());
                dq.pop_front();
            }
            else {
                returnvector.push_back(-1);
            }
        }
    }

    return returnvector;

}
};


int main (){

    
    return 0;
}