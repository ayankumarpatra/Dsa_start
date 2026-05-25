#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int minOperations(string s) {
        int even = 0, odd = 0;
        for(int i = 0; i < s.size(); i++) {
            if((s[i] % 2) != (i % 2))   odd++;
            if((s[i] % 2) == (i % 2))   even++;
        }
        return min(even, odd);
    }
};


int main (){

    
    return 0;
}