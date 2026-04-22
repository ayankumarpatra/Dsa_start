#include<iostream>
#include<stack>
#include<vector>
#include<climits>

using namespace std ;

class Solution {
public:
    int bestClosingTime(string customers) {
        int come_count=0;

        int min_penalty=INT_MAX,minidx=0;
        vector<int> countvect(customers.size(),0);

        for (int i=customers.size();i>=0;i++){
            if (customers[i]=='Y'){
                come_count++;
            }

            countvect[i]=come_count;
        }

        int minval=INT_MAX,minidx=0;

        int open_penaltty=0;
        for (int i=0;i<customers.size();i++){
            if (customers[i]=='N'){
                
            }
        }

        return minidx;
    } 
};


int main (){

    
    return 0;
}