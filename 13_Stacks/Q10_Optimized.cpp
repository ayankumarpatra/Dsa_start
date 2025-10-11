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
        int i,j,max,Vector_Size=nums.size(),temp;
        vector<int> Max_Window;
        for(i=0;i+k-1<Vector_Size;i++){
            stack <int> st;
            temp=k;
            j=i;
            max=INT_MIN;// use climits for minn
            while (temp--!=0)
            {
                max=nums[j]>max?nums[j]:max;
                j++;
            }
            Max_Window.push_back(max);

        }
        return Max_Window;
    }

int main (){

    return 0;
}