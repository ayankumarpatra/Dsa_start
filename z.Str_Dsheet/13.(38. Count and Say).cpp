#include<iostream>
#include<string>
#include<vector>

using namespace std ;

class Solution {
public:
    string FillStr(int n,string s){
        if (n==1){
            s+="11";
            return s;
        }
        string tempstr="";
        for (int i=0;i<s.size();i++){
            char currchar=s[i];
            int count =1;
            while (i<s.size() && s[i]==currchar)
            {
                i++;
            }
            
            
        }
        return s+FillStr(n-1,s);
    }

    string countAndSay(int n) {
        string s1="",s="";
        int i=0;

        s=FillStr(n,s);

        while (i<s.size()){
            char count=0;
            char currchar=s[i];

            while (i<s.size() && s[i]==currchar)
            {
                i++;
                count++;
            }

            s1+=currchar;
            s1+=count;
            
        }
        return s1;
    }
};


int main (){
    
    Solution sol;

    string s=sol.countAndSay(3);

    return 0;
}