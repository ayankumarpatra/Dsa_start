#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort (prices.begin(), prices.end());
        sort(discounts.begin(),discounts.end());

        int pricelim=prices.size() -1;
        double retval=0;
        for (int i=discounts.size()-1;i>=0 && pricelim>=0; i--){
            retval+= prices[pricelim--]*(100-discounts[i])/100.0;
        }

        while (pricelim>=0)
        {
            retval+= prices[pricelim--];
        }
        
        return retval;
    }
};

int main (){

    
    return 0;
}