#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

// Find subArrays of a given array but by recursion 

void PrintSubArray(vector<int> &Mainarr ,int start,int end){

    // function to print he array 
    cout<<"{";
    for (int i=start;i<=end;i++){
        cout<<Mainarr[i]<<" ";
    }
    cout<<"}"<<endl;

// first stop if the index go out of bounds

if(end==Mainarr.size()){
    return;
}

}

int main (){

    vector<int> mainarr={5,6,7,8};
    vector<int> subarr;
    
    PrintSubArray(mainarr,0,mainarr.size());
    return 0;
}

