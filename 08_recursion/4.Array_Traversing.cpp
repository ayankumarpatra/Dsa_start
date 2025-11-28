#include<iostream>
#include<vector>
using namespace std ;

void ArrayPrinter(int arr[] ,int noofelements,int start ){
    if (start==noofelements)
    {
        cout<<endl;
        return;
    }
    
    cout<<arr[start]<<", ";
    ArrayPrinter(arr,noofelements,start+1);
}

void VectorPrinter(vector<int> &v,int count){// must use &vector , else it will be creating seperate vector copies
    if(count==v.size()){
        cout<<endl;
        return;
    }

    cout<<v[count]<<", ";
    VectorPrinter(v,count+1);
}



int main (){

    int arr[]={5,6,7,8,9};

    int no_of_elements=sizeof(arr)/sizeof(arr[0]);

    ArrayPrinter(arr,no_of_elements,0);

    // to print a vector 

    vector<int> Arrv={5,6,2,3,5};

    VectorPrinter(Arrv,0);

    return 0;
}