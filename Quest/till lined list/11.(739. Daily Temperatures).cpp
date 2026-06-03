#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> returnvector(temperatures.size(),0);

        stack<int> st;

        for (int i=0;i<temperatures.size();i++){

            while (!st.empty() && temperatures[st.top()]<temperatures[i])
            {
                returnvector[st.top()]= i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return returnvector;
    }
};


int main (){

    
    return 0;
}