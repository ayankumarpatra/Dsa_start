#include<iostream>
#include<stack>
#include<string>

using namespace std ;



class Solution {
public:
    string removeOuterParentheses(string s) {
        int count =0;
        string return_str;

        for (int i=0;i<s.size();i++){
            if (s[i]=='('){
                if (count>0){// see >0 as first time count=0 so it will not include 
                    // so as per given problem , outer string will be removed;
                    return_str+='(';
                }
                count++;
            }
            else if (s[i]==')'){

                count --;
                if (count>0){
                    return_str+=')';
                }
            }
        }
        return return_str;
    }
};


int main (){

    
    return 0;
}