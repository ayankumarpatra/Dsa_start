#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;

class Solution {
public:
    string makeLargestSpecial(string s) {
        int count=0,st=0;
        string str;
        vector<string>returnvector;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){count++;}
            else count--;
            if(count ==0){
                string substr=s.substr(st+1,i-st-1);
                string a="1"+makeLargestSpecial(substr)+"0";
                returnvector.push_back(a);
                st=i+1;
            }
        }
        sort(returnvector.begin(),returnvector.end(),greater<>());
        for(auto i:returnvector){
          str+=i;
        }
        return str;
    }
};


int main (){

    
    return 0;
}