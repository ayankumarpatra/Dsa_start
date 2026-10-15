#include<iostream>
#include<stack>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std ;


// approach 1 fail actually we need to search one by one not the global max 2

/*

class Solution {
    public:
    int totalFruit(vector<int>& fruits) {
        
    unordered_map<int,int> um; // key , val pair 
    
    for (auto currfruit: fruits){
        um[currfruit]++;
    }
    
    int first =0,second=0;
    
    for (auto currpair:um){
        
    if (currpair.second >= first){
        if (first!=0 && first>second ){
            second = first;// update 2nd largest
        }
        first = currpair.second;
    }
    
    else if(currpair.second >= second) {
        second=currpair.second;
    }
    
}

return first+second;
}
};
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int,int> um; // key , val pair 

        for (auto currfruit: fruits){
            um[currfruit]++;
        }

        int first_max_freq =0,second_max_freq =0,maxelement=-1;

        for (int i=0;i<fruits.size();i++){
            int curr_freq= um.find(fruits[i])->second;

            if (curr_freq>first_max_freq && fruits[i]!=maxelement ){
                
                first_max_freq=curr_freq;
                maxelement=fruits[i];
            }
            else if (fruits[i]!=maxelement) {
                second_max_freq=curr_freq;
            }
        }

        return first_max_freq+second_max_freq;
    }
};

int main (){
    

return 0;
}