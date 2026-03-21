#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int Num_Pointer=1,maxnum=target[target.size()-1],Vectorpointer=0,vectorlen=target.size();
        vector<string> Returnvector;

        while (Num_Pointer<=maxnum){
            Returnvector.push_back("Push");

            if(Num_Pointer==target[Vectorpointer]){
                 Vectorpointer++;
            }
            else{
                    Returnvector.push_back("Pop");                
                }
            Num_Pointer++;
            }
            return Returnvector;
        }
};


int main (){

    
    return 0;
}