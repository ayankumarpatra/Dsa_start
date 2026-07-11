#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int minv (string &mainstr,int i=0){
        
    }
    int minimumDeleteSum(string s1, string s2) {
        int str1val= 0;
        int str2val= 0;
        int i=0;

        bool stop1=false ,stop2=false;

        while (!stop1 && !stop2)
        {
            if(i<s1.length()){
                str1val+=char(s1[i]);

                if (i=s1.length()-1){
                    stop1=true;
                }
            }

            if(i<s2.length()){
                str2val+=char(s2[i]);

                if (i=s2.length()-1){
                    stop1=true;
                }
            }


        }

        if (str1val>str2val){

        }
        


    }
};


int main (){

    
    return 0;
}