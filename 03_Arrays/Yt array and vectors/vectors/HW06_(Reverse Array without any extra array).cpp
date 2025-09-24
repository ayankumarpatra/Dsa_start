// (Reverse Array without any extra array but using function )

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

void ReverseArray(vector<int> &original){

    reverse(original.begin(),original.end());

}

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

    ReverseArray(v);
    cout<<"\nAfter revverse : \n";

    for (int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    return 0;
}