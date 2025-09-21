#include<iostream>
#include<vector>

using namespace std ;
int main (){
    int sz,val;
    cout<<"Enter the size : ";
    cin>>sz;

    vector<int> arr(sz);

    for (int i=0;i<sz;i++){
        cout<<"Enter value"<<i+1<<" :";
        cin>>val;
        arr.push_back(val);
    }
    return 0;
}