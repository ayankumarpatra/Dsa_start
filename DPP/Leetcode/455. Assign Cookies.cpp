#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int findContentChildren(vector<int>& child, vector<int>& cookies) {
        // sort + 2 pointer 

        sort (child.rbegin(),child.rend());

        sort (cookies.rbegin(),cookies.rend());

        int child_index=0,cookies_index=0,eaten=0;

        while (child_index<child.size() && cookies_index<cookies.size()  )
        {
            if (child[child_index] <= cookies[cookies_index]){
                cookies_index++;
                eaten++;
            }
            child_index++;
        }

        return eaten;
        
    }
};

int main (){

    
    return 0;
}