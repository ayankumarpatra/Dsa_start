#include<iostream>
#include<stack>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std ;


/*
// approach 1 fail actually we need to search one by one not the global max 2

and also ok , so the main thing is we have to pick all the consecutive fruits ; i mean i am trying to resetting the least basket and keep the max basket , but if 2 consecutive element is different ; we have to pick both , even have to replace the max basket too ... so i misunderstood the q : )

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
        unordered_map<int,int> um;

        int left =0,right=0,n=fruits.size();

        int max_fruits=0;

        while (right<n)
        {
            um[fruits[right]]++;

            while (um.size()>2)
            {
                    auto last_fruit=um.find(fruits[left]);

                    last_fruit->second--;

                    if (last_fruit->second==0){
                        um.erase(last_fruit);
                      }

                      left++;
                }
                      max_fruits= max (max_fruits, right - left + 1);
                      right++;
            }

            return max_fruits;
        }
};

int main (){
    

return 0;
}