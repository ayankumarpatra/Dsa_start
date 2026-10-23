#include<iostream>
#include<string>
#include<algorithm>

using namespace std ;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry =0;
        int alen = a.length() -1; //1
        int blen = b.length() -1; //0

        while(alen>=0 || blen>=0 || carry)
        {
            if(alen>=0) carry = carry +a[alen--] - '0';
            if(blen>=0)  carry = carry+b[blen--] -'0';

            res+=carry%2+'0';
            carry/=2;

        }
        reverse(begin(res), end(res));
        return res;

    }
};



int main (){

    
    return 0;
}