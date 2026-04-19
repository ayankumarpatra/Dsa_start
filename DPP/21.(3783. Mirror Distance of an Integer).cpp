#include<iostream>
#include<string>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int mirrorDistance(int n) {
        string str=to_string(n);
        reverse(str.begin(),str.end());
        return (abs(stoi(str))-n);
    }
};


int main (){

    
    return 0;
}