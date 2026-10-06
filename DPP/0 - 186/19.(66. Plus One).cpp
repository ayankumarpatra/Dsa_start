#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

    int maxlen= digits.size();
    
    
    if(digits[maxlen-1]==9){
        
        if(digits.size()==1){
        digits.resize(digits.size()+1);
        digits.back()=0;
        digits[maxlen-1]=1;
        return digits;
        }

        int i=maxlen-1;
        bool ireach0=false;
        while (i>=0)
        {
            if(digits[i]==9){
                digits[i]=0;
            }

            else if(digits[i]!=9){
                digits[i]=digits[i]+1;
                break;
            }


            if (i==0){
                ireach0=true;
            }

            i--;
        }

        if (ireach0){
            digits[0]=0;
            digits.insert(digits.begin(),1);

        return digits;

        }
        

    }

    else {
        digits [maxlen-1]=digits[maxlen-1]+1;
    }

    return digits;

    
        
    }
};


int main (){

    
    return 0;
}