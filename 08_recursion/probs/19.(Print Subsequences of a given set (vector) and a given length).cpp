// Print Subsequences of a given set (vector) and a given length 

#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

void Print_Subsequences(vector<int> mainset,vector<int> subset,int i, int length){
    // added after thinking about basecase 
    //if(mainset.size()-i<length || length>mainset.size() || length==0){
    //    return;
        
    //}
    /*
            actually i just thought that if i reach in such a index , from where i cant get any subset of 
            length , then why travarse more 

            i mean let given array is {4,3,2,1} and given len is 3 
            so when i reach index 0 , good , 1 good , 2 .. cant as arr size=4 , so  4-2 =2 thats <3 
            so i cant gent any subset more (i mean as i cant go further to fromt again , order must 
            be preserved )
    }
    
    but this idea didnt worked , so dropping it 
        */ 
    if(mainset.size()-i<length-subset.size()){
        return;
    }
    //basecase 

    if(i==mainset.size()){
        if(subset.size()==length){
            cout<<"{";
            for (int element :subset){
                cout<<element<<" ";
            }
            cout<<"}\n";
        }
        return;
        }

    // adding the curr element in the subset 
        subset.push_back(mainset[i]);
        Print_Subsequences(mainset,subset,i+1,length);

    // removing the last added element
        subset.pop_back();
        Print_Subsequences(mainset,subset,i+1,length);


}


int main (){

    vector<int> mainset = {1,2,3,4};
    vector<int> subset;

    int length=3;
    Print_Subsequences(mainset,subset,0,length);
    
    return 0;
}