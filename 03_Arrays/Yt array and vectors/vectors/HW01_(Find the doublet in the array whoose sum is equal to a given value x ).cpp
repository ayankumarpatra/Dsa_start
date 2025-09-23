/*
Find the doublet in the array whoose sum is equal to a given value x 

eg if array is 1 2 3 4 5 
and x given is 7 print 2 +5 , dont print anything if single value is equal like if x=5 , dont give 5 only , write no doublet found 



// self retry , 
// my old issues 1. check same element with it again , 2. wrong print not found etc ;

// method 1 bruteforce 

#include<iostream>
#include<vector>
using namespace std ;
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
    
    cout<<endl;

    for (int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    int target,found=0;
    cout<<"Enter the target sum element : ";
    cin>>target;

    for (int i=0;i<v.size();i++){
        for (int j=0;j<v.size();j++){
            if (v[i]+v[j]==target){
                cout<<v[i]<<" + "<<v[j]<<" = "<<target;
                found=1;
                break;
            }
        }
        if (found) break;  
    }

    if(!found) cout<<"Not found \n";

    return 0;
}


2pointer  approach , will sort first then do;
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
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
    cout<<endl;
    for (int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    cout<<"\nEnter the target sum element : ";
    cin>>Element;

    sort(v.begin(),v.end());
    int lefts=0,rights=v.size()-1,find=1;
    while (lefts!=rights)
    {
        if (v[lefts]+v[rights]==Element){
            cout<<Element<<" = "<<v[lefts]<<" + "<<v[rights];
            find=0;
            break;
            
        }
        if (v[lefts]+v[rights]>Element){
            rights--;
        }
        if (v[lefts]+v[rights]<Element){
            lefts++;
        }
    }
    if(find) cout<<"Not found ";
    
    return 0;
}