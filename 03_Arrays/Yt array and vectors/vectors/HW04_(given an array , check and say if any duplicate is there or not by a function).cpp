//(given an array , check and say if any duplicate is there or not by a function)
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;


bool DuplicateVectorChecker(vector<int> *v ){
    sort(v->begin(),v->end());
    for (int i=0;i<v->size()-1;i++){
        if((*v)[i]==(*v)[i+1]){
            return true;
        }
    }
    return false ;
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

    if(DuplicateVectorChecker(&v)){
        cout<<"\nDuplicates present \n";
    }
    else {
        cout<<"\nNo duplicates present \n";
    }
    return 0;
}


alternate and simpler version 

instead of pointer , just send by reference , as we arent editing anything 


*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

bool DuplicateVectorChecker(vector<int> &v){
    sort(v.begin(),v.end());
    for (int i=0;i<v.size()-1;i++){
        if(v[i]==v[i+1]){
            return true;
        }
    }
    return false;
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

    if(DuplicateVectorChecker(v)){
        cout<<"\nDuplicates present \n";
    }
    else {
        cout<<"\nNo duplicates present \n";
    }
    return 0;
}