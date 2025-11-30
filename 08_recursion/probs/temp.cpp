#include<iostream>
#include<vector>

using namespace std ;

void GenerateSubset(const vector <int> &arr,vector <int> &ans,int i){
    if(i==arr.size()){
        cout<<"{";
        for (int x :ans) cout<<x<<" ";
        cout<<"}\n";
        return;
    }

    ans.push_back(arr[i]);// include current element
    GenerateSubset(arr,ans,i+1);

    ans.pop_back();// backtracking 
    
    GenerateSubset(arr,ans,i+1);// excluding current element 
}


int main (){

   vector <int> mainset={4,5,6,7} ;
   vector <int> subset={};

   GenerateSubset(mainset,subset,0);

    return 0;
}