#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std ;

// v1 
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set <int> st;
        vector<string> revval;

        for (int i=0;i<nums.size();i++){
            st.insert(nums[i]);

            string s= to_string(nums[i]);
            reverse(s.begin(),s.end());

            revval.push_back(s);
        }

        int count=st.size();

        for (int i=0;i<nums.size();i++){
            int tempnum=stoi(revval[i]);

            if (st.find(tempnum)!=st.end()){
                continue;
            }
            else{
                count++;
            }
        }

        return count;
    }
};


//v2

class Solution {
public:
    int revnum(int num){
        int temp=0;

        while (num>0)
        {
            temp=(temp*10)+(num%10);
            num=num/10;
        }

        return temp;
        
    }

    int countDistinctIntegers(vector<int>& nums) {
        // putting all the elements in the set only 

        unordered_set <int> us;

        for(int i=0;i<nums.size();i++){
            us.insert(nums[i]);
        }
                
        for(int i=0;i<nums.size();i++){
            int tempnum=revnum(nums[i]);

            us.insert(tempnum);
       }

       return us.size();// finally set only consist the main unique + rev unique numbers
    }
};

int main (){

    
    return 0;
}