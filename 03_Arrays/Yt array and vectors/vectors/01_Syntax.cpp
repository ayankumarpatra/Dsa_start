#include<iostream>
#include<vector>

using namespace std ;
int main (){
    int sz,val;
    cout<<"Enter the size : ";
    cin>>sz;

    vector<int> arr(sz);
    // we can also initialize a vector by some default values 
    // vector<int> arr(n,8)// initialize all value by 8 , usually when we write vector<int> arr(size), usually all vale becomes 0 , then we modify

    for (int i=0;i<sz;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    for (int i=0;i<arr.size();i++){
        cout<<"Enter value"<<i+1<<" :";
        cin>>val;
        arr.push_back(val);
    }
    
    for (int i=0;i<sz;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    /*
    functions 

    1. vector_name .size() returns the no of capacity that are filled by elements (total no of empty boxes )
    2. vector_name .capacity() returns the capacity only ( total no of boxes , filled + empty)
    3. vector_name .push_back (value)// push back the value you wish to add after vecor full , if vector not full , we can add like arr[i]=this ;
    4. vector_name .pop_back() remove last element , size=size-1, so make sure size !=0

    // soring a vector 
    */
    return 0;
}