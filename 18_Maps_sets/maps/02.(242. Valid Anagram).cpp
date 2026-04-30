#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std ;


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }

        unordered_map<char,int> mp;

        int i=0;

        for (i;i<s.size();i++){
            if(i<t.size() && s[i]==t[i]){
                continue;
            }
            mp[s[i]]++;
        }

        for (i=0;i<t.size();i++){
            if(i<s.size() && s[i]==t[i]){
                continue;
            }
            
            if(mp.find(t[i])!=mp.end()){
                if (mp.find(t[i])->second==0){
                    return false;
                }
                else {
                mp.find(t[i])->second--;
                }
            }
            else {
                return false;
            }
        }
        return true;
    }
};



int main (){

    
    return 0;
}