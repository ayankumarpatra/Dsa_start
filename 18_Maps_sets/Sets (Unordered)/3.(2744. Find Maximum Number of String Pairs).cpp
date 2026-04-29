#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> us;

        int count=0;
        
        for (int i=0;i<words.size();i++){
            
            string currstr=words[i];
            reverse(currstr.begin(),currstr.end());// geeting curr word and reversing it 
            
            if(words[i]==currstr){
                continue;// if both curr string and the rev string is same its the same string
                // eg if aa its rev also aa so just skip it 
            }

            
            if (us.find(currstr)!=us.end()){// means reverse of the curr string exist
                count++;
            }
            else {
                us.insert(words[i]);// adding the curr word in the set
            }

        }

        return count;
    }
};


int main (){

    
    return 0;
}