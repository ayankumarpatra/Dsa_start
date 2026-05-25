#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std ;

class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.size()!=goal.size()){
            return false;
        }
        
        s=s+s;

        // see if the goal is a substring of the main string s+s then it exists else it doesnt exist

        for (int i=0;i<s.size();i++){
            if (s[i]==goal[0]){
                int str1=i;
                int str2=0;

                bool all_match=true;

                while (str1<s.size() && str2<goal.size())
                {
                    if(s[str1]==goal[str2]){
                        all_match=true;
                    }
                    else{
                        all_match=false;
                        break;
                    }
                    str1++;
                    str2++;
                }

                if (str2!=goal.size()){
                    all_match=false;
                }

                else if (all_match){
                    return true;
                }
            }
        }

        return false;     
    }
};


int main (){

    
    return 0;
}