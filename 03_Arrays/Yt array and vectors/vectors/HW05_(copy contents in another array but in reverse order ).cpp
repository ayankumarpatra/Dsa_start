//(copy contents in another array but in reverse order )
#include<iostream>
#include<vector>
using namespace std ;

    void CopyVectorReverse(vector<int>&mainvector , vector<int>&copyvector){
        if(mainvector.size()==0){
            cout<<"Main vector is empty\n";
            return;
        }
        int z=mainvector.size();
        for(int i=0;i<z;i++){
            copyvector[z-i-1]=mainvector[i];
        }
        cout<<"Copy successfull.";
    }

    // or only 1 line logic in cpp *** reverse_copy(v.begin(), v.end(), v2.begin()); ***, use algorithms 

    /*
     // Reverse the vector in-place
    reverse(v.begin(), v.end());
    */

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
    
    cout<<"Main vector is : \n";
    for (int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    vector<int> v2 (v.size());
    
    CopyVectorReverse(v,v2);

    cout<<"\nAfter copy vector is : \n";

    for (int i=0;i<v.size();i++){
        cout<<v2[i]<<" ";
    }

    return 0;
}