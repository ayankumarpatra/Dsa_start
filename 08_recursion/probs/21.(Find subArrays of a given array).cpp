#include<iostream>
#include<stack>
#include<vector>

using namespace std ;
// Find subArrays of a given array but by recursion 

void PrintSubArray(vector<int> &Mainarr ,vector <int> subarr,int i=0){
    if(Mainarr.size()==i){
        cout<<"{";
        for (int element : subarr){
            cout<<element<<",";
        }
        cout<<"}\n";
        return;
    }

    // including the current element 
    subarr.push_back(Mainarr[i]);
    PrintSubArray(Mainarr,subarr,i+1);
    
    
    // ecluding the curr element 
    subarr.pop_back();
    PrintSubArray(Mainarr,subarr,i+1);


}


int main (){

    vector<int> mainarr={5,6,7,8};
    vector<int> subarr;
    
    PrintSubArray(mainarr,subarr,0);
    return 0;
}