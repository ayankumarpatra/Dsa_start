#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> returnvect =prices;

        for (int i=0;i<prices.size();i++){
            int j=i+1;
             while (j<prices.size())
             {
                if (prices[j]<=prices[i]){
                    break;
                }
                j++;
             }
            if (j<prices.size() && prices[j]<=prices[i]){
                returnvect[i]-=prices[j];
            }

        }
        return returnvect;
    }
};

// stack approach 
 

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> returnvect=prices;
        stack <int> st;
        for (int i=0;i<prices.size();i++){
            while (!st.empty() && prices[st.top()]>=prices[i])
            {
                returnvect[st.top()]-=prices[i];
                st.pop();
            }
            st.push(i); 
        }
        return returnvect;
    }
};


int main (){

    
    return 0;
}