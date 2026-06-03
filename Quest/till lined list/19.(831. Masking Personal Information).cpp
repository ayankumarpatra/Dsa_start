#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    string maskPII(string s) {

        string rstr="";

        bool isnum=false;

        // if it contain @ it must be a email;
            bool gotat=false;
            rstr+=tolower(s[0]);
            rstr+="*****";

            for (int i=0;i<s.size();i++){
                if (gotat){
                    rstr+=tolower(s[i]);
                }
                else if (i+1<s.size() && s[i+1]=='@'){  
                    rstr+=tolower(s[i]);
                    gotat=true;
                }
            }

        
        // else it obviously its a number 
        if (gotat){
            return rstr;
        }
        else{
            rstr="";
        }
            int numlength=0;

            queue<char> q;

            for (int i=0;i<s.size();i++){
                if (!isdigit(s[i])){
                    continue;
                }
                else{
                    numlength++;
                    q.push(s[i]);
                    if(q.size()>4){
                        q.pop();
                    }
                }
            }

            
            if (numlength>=10){
                if (numlength==10){
                    rstr+="***-***-";
                }
                else if (numlength==11){
                    rstr+="+*-***-***-";
                    
                }
                else if (numlength==12){
                    rstr+="+**-***-***-";
                    
                }
                else if (numlength==13){
                    rstr+="+***-***-***-";
                    
                }
                while (!q.empty())
                {
                    rstr+=q.front();
                    q.pop();
                }
        }
        return rstr;
    }
};


int main (){

    
    return 0;
}