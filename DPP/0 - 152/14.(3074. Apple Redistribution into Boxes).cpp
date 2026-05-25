#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std ;


class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());

        int sum= accumulate(apple.begin(),apple.end(),0);
        int count=0;

        for (int i=0;i<capacity.size();i++){
            sum-=capacity[i];
            count++;
            
            if(sum<=0){
                break;
            }
        }

        return count;

    }
};


int main (){

    
    return 0;
}