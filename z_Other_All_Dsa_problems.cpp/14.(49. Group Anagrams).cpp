#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:


vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
    vector<vector<string>> returnvect;
    if (strs.size()<2){
        returnvect.push_back(strs);
        return returnvect;
    }
    
    unordered_map <string ,vector<string> > um;

    string mainstr;
    
    for (string currstring : strs){
        mainstr=currstring;

        sort(currstring.begin(),currstring.end());

        //     auto finder=um.find(currstring);

        // if (finder!=um.end()){
        //     finder->second.push_back(mainstr);
        // }
        // else {
        //     vector<string> tempss;
        //     tempss.push_back(mainstr);
        //     um[currstring]= tempss;
        // }
        um[currstring].push_back(mainstr); // better one liner for the whole lines 
    }

    for (auto key:um){
        returnvect.push_back(key.second);
    }   
    
        return returnvect;
    }
};


int main (){

    
    return 0;
}