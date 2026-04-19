#include<iostream>
#include<string>
#include<vector>

using namespace std ;

class Solution {
public:
    string FillStr(int n){// taking number to make the string out of it 
        if (n==1){
            return "1";// base case for 1 , one 1 only 
        }

        string prev= FillStr(n-1);

        string temp="";
        for(int i=0;i<prev.size(); ){// no i++ as we have to move to next char 
            int j=i;
            int count=0;
            while (j<prev.size() && prev[i]==prev[j])
            {
                count++;
                j++;
            }
            temp+=to_string(count);
            temp+=prev[i];
            i=j;           
        }
        return temp;
    }

    string countAndSay(int n) {
        string s1="",s="";
        int i=0;

        s=FillStr(n);

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
    
}