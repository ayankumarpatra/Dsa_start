#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std ;


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> um;// a key value pair and always key<=val

        vector<int> returnvect(A.size(),0);
        vector<int>freq(A.size()+1,0);//said that both vector are equal
        int count=0;

        for (int i=0;i<A.size();i++){
            freq[A[i]]++;
            freq[B[i]]++;

            if (freq[A[i]]==2){ count++; }
            if (freq[B[i]]==2){ count++; }

            returnvect[i]=count;
            // dont reset count , see suppose you reached till 7 so till 6 no of commons will be same 
        }

        return returnvect;
    }
};



int main (){

    
    return 0;
}