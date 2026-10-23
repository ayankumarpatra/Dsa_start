#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    void reverseString(vector<char>& s) {
        int front =0 , back = s.size()-1;

        while (front<back)
        {
            swap(s[front++],s[back--]);
        }
        
    }
};


int main (){

    
    return 0;
}