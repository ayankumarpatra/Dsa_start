//rotate a given array a , by k times , where k is non -ve , but k can be greater than the size 

#include<iostream>
#include<vector>
using namespace std ;


// not sure about rest code , only checked about this solution part only 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
    }
};










int main (){
    int No_Of_Elements,Element;
    cout<<"Enter No of Elements : ";
    cin>>No_Of_Elements;

    vector<int> v(No_Of_Elements);
    
    for (int i=0;i<No_Of_Elements;i++){
        cout<<"Enter the Element : ";
        cin>>Element;
        v[i]=Element; 
    }
    
    for (int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }


    return 0;
}