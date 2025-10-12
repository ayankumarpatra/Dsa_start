#include<iostream>
#include<vector>
#include<climits>
#include<stack>
using namespace std ;

/*

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]

*/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //Bruteforce solution
        //Next greater element array
        int i,Vector_size=nums.size();
        stack <int> st;
        vector <int> Next_Greater_element(Vector_size,-1);
        for(i=Vector_size-1;i>=0;i--){
            while (st.size()>0 && nums[st.top()]<=nums[i])
            {
            st.pop();
            }
            if(st.size()!=0){
                Next_Greater_element[i]=st.top();
            }

            st.push(i);
        }
    }

int main (){

    return 0;
}