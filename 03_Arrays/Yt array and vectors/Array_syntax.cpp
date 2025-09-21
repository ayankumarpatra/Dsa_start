// please refer to array from a good resource , i have a medium good idea about array so i am just 
// revising , please consider to watch a good resource 

#include<iostream>
using namespace std ;
int main (){

    int arr[5];
    // if you dont wanna give size , write like arr[]=[5,6,7,3]... automatically size will be allocated 


    for (int i=0;i<5;i++){
        arr[i]=i+5;
    }// directly give all element the value 
    
    for (int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }


    // Array indexing is starts from 0 and goes to size-1


    // sizeof operator ;  sizeof(datatype name )... returns the size of that whole datatype

    // eg for sizeof(arr), give whole size of arr , like if 4 int , will return 16 

    // to get no of elemnts do    sizeof(arr)/sizeof(arr[0])    so total size/izeofeach = no of element 

    // contigious memory allocation 
    return 0;
}