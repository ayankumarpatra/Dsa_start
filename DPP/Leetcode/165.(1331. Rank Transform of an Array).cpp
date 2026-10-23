#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> arrcopy=arr;// copy of arr
        
        sort(arr.begin(),arr.end()); // sorting the vector


        unordered_map<int,int> um;// key , idx pair

        int idx=1;// to keep track of indexes and avoid duplicate index for same element;
        for ( int i=0;i<arr.size();i++){
            auto temp= um.find(arr[i]);

            if ( temp == um.end() ){ // if not exist then add
                pair <int,int> ins;
                ins.first=arr[i];
                ins.second=idx;
                um.insert(ins);
                idx++;
            }
        }
        
        vector<int> idxvect;
        for ( int i=0;i<arr.size();i++){
            
            idxvect.push_back(um.find(arrcopy[i])->second); // push back according to main index
        }


        return idxvect;
    }
};



int main (){

    
    return 0;
}