#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    string reverseWords(string s) {
        stack <string> str;
        string temp_str;

        for (int i=0;i<s.size();i++){
            if(s[i]!=' '){
                temp_str+=s[i];
            }
            else {
                if (temp_str!=""){
                    str.push(temp_str);
                }
                temp_str="";
            }
        }
        
        if (temp_str!=""){
            str.push(temp_str);
            temp_str="";
            }

        while (str.size()>0)
        {
            temp_str+=str.top();
            if (str.size()>1){
                temp_str+=' ';
            }
            str.pop();
        }
        
        return temp_str;
        
    }
};

// approach 2 

class Solution {
public:
    string reverseWords(string s) {
        string resultstr;

        string tempstring="";


        for (int i=s.size()-1;i>=0;i--){

            if (s[i]==' '){
                if (tempstring!=""){
                    resultstr=resultstr+tempstring;
                    tempstring="";
                }
                while (i>=0 && s[i]==' ')
                {
                    i--;
                }
                
            }
            else {
                tempstring=s[i]+tempstring;
            }
        }
        if (tempstring!=""){
            resultstr=resultstr+tempstring;
        }

        while (resultstr[resultstr.size()-1]==' ')
        {
            resultstr.pop_back();
        }
        

        return resultstr;
    }
};



int main (){

    
    return 0;
}