//239. Sliding Window Maximum


#include<iostream>
#include<vector>
#include<stack>
using namespace std ;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        stack<int> st;
        int i , vector_size=nums.size();

        vector<int> NextGreaterElement;
        vector<int> TempGreaterElement(vector_size,-1);

        for(i=vector_size-1;i>=0;i--){
            while (st.size()>0 && nums[st.top()]<=nums[i]){
                    st.pop();
            }
            if(st.size()!=0){
            TempGreaterElement[i]=st.top();
            }
            st.push(i);
        }

        for(int i=0;i<vector_size-k;i++){
            int j=i;
            while (TempGreaterElement[j]!=-1 && TempGreaterElement[j]<i+k)
            {
                j=TempGreaterElement[j];
            }
            NextGreaterElement.push_back(nums[j]);
        }
        return NextGreaterElement;
    }
};

int main (){


    return 0;
}
