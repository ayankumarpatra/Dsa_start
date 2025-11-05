#include<iostream>
#include<vector>
#include<stack>
using namespace std ;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // creating an array with next greater element index 
        vector<int> NextGreaterEm(nums.size(),-1);
        stack <int> st;
        vector<int> MaxSlide;

        for(int i=nums.size()-1;i>=0;i--){
            while (st.size()>0 && nums[st.top()]<=nums[i])
            {
                st.pop();
            }
            if(st.size()!=0){
                NextGreaterEm[i]=st.top();
            }
            st.push(i);
        }

        for(int i=0;i<=nums.size()-k;i++){
            int j=i;
            while(NextGreaterEm[j]!=-1 && NextGreaterEm[j]<i+k){
                j=NextGreaterEm[j];
            }
            MaxSlide.push_back(nums[j]);
        }

        return MaxSlide;
    }
};


int main (){

    return 0;
}