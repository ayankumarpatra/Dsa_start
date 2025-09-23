#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
int main (){
    int No_of_Elements,Element;
    cout<<"Enter no of elements : ";
    cin>>No_of_Elements;

    vector<int> v(No_of_Elements);
    for (int i=0;i<v.size();i++){
        cout<<"Enter the element : ";
        cin>>Element;
        v[i]=Element;
    }
    cout<<endl;
    
    for (int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    //Sorting reverse 

    /*
    2 ways , either reverse the sort 
   sort(v.begin(),v.end());
   reverse(v.begin(),v.end());

    */

    // or traditional way 

    sort(v.begin(),v.end(),greater<int>());


    return 0;
}