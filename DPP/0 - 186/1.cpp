#include<iostream>
#include<stack>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map <int,int> um;

        while (n>0)
        {
            int currnum=n%10;
            n/=10;

            auto findnum=um.find(currnum);

            if (findnum!=um.end()){
                findnum->second++;
            }
            else {
                um.emplace(currnum,1);
            }
        }

        int count=0;
        
        for (auto em:um){
            count+=(em.first*em.second);
        }

        return count;
    }
};


int main (){

    
    return 0;
}