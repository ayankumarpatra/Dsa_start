#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>

using namespace std ;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map <int,int> um;// value , freq pair;

        for (int i=0;i<arr.size();i++){

            // checking if available or not 

            auto check=um.find(arr[i]);

            if (check==um.end()){
                um[arr[i]]=1;// if element isnt existed till now then creating
            }

            else {
                check->second++;// if exist , just increase the freq 
            }
        }

        unordered_set<int> Already_got;

        for (auto currpair:um){

            if (Already_got.find(currpair.second)!=Already_got.end()) {
                return false;
            }

            Already_got.insert(currpair.second);
        }

        return true;
    }
};


int main (){

    
    return 0;
}