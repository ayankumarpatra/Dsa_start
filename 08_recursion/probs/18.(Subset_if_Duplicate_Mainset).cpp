#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std ;

void Generation_helper(vector<int> &Mainset , vector<int> &subset, int i=0){
    // basecase
    if(i==Mainset.size()){
        cout<<"{";
        for (int element : subset){
            cout<<element<<", ";
        }
        cout<<"}\n";
        return;
    }

    // include the curr element in subset
    subset.push_back(Mainset[i]);
    Generation_helper(Mainset,subset,i+1);
    
    // exclude the last added element 
    subset.pop_back();

                 // removing the similar elements 
    while ( i+1<Mainset.size() && Mainset[i]==Mainset[i+1])
    {
        i++;
    }
    
    Generation_helper(Mainset,subset,i+1);
    
}

void Generate_Subset (vector<int> &Mainset , vector<int> &subset, int i=0){
    sort(Mainset.begin(),Mainset.end());

    Generation_helper(Mainset,subset,0);

}


int main (){

    vector<int> mainset={1,1,2,1,8};
    vector<int> subset;

    Generate_Subset(mainset,subset,0);
    
    return 0;
}