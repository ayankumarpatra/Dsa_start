#include<iostream>
#include<vector>

using namespace std ;

void Print_Subset(vector<int> mainset,vector <int> subset,int i=0){
    if(i==mainset.size()){
        cout<<"{";
        for (int element : subset){
            cout<<element<<" ";
        }
        cout<<"} \n";
        return;
    }

    // include curr element 

    subset.push_back(mainset[i]);
    Print_Subset(mainset,subset,i+1);


    //removing the last added element 
    subset.pop_back();
    Print_Subset(mainset,subset,i+1);
}


int main (){

    vector<int> pri ={5,6,7,8};
    vector<int> sub;

    Print_Subset(pri,sub,0);
    return 0;
}