#include<iostream>
#include<vector>

using namespace std ;

void PrintSubsets(const vector<int> &mainvector, vector<int> &subvector,int i=0){
    if (i==mainvector.size()){
        cout<<"{";//basecase
        for (int x : subvector) cout<<x<<" ";
        cout<<"}";

    } 
    //
    subvector.push_back(mainvector[i]);
    PrintSubsets(mainvector,subvector,i+1);

    subvector.pop_back();
    PrintSubsets(mainvector,subvector,i+1);

}


int main (){

    
    return 0;
}