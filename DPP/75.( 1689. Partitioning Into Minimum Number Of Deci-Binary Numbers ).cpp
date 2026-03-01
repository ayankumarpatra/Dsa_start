#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


class Solution {
public:
    int minPartitions(string n) {
        
        int max_digit = 0;

        // find largest digit in string
        for (char c : n) {
            max_digit = max(max_digit, c - '0');
        }

        return max_digit;
    }
};

int main (){

    
    return 0;
}