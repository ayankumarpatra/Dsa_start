#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        // string based approach 

        vector<int> returnvector;

        for (int temp:nums){
            string str=to_string(temp);

            for (int i=0;i<str.size();i++){
                returnvector.push_back(int(str[i]-'0'));
            }
        }

        return returnvector;
    }
};


// stack bassed approach 


class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        stack<int> st;
        vector<int> returnvector;
        for (auto val:nums){
            while (val!=0)
            {
                st.push(val%10);
                val/=10;
            }
            while (!st.empty())
            {
                returnvector.push_back(st.top());
                st.pop();
            }
            
        }
        return returnvector;
    }
};


int main (){

    
    return 0;
}