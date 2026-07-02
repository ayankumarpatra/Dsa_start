#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

void array_merger(vector<int>& arr1,vector<int>& arr2,vector<int>& result){
    // array are already sorted 
    int len1=0,len2=0,resultlen=0;

    while (len1<arr1.size() && len2<arr2.size())
    {
        if (arr1[len1]<arr2[len2]){
            result[resultlen++]=arr1[len1++];
        }
        else{
           result[resultlen++]=(arr2[len2++]);
        }
    }
    
    while (len1<arr1.size())
    {
        result[resultlen++]=(arr1[len1++]);
    }
    while (len2<arr2.size())
    {
       result[resultlen++]=(arr2[len2++]);
    }
    
}

void merge_sort(vector<int>& v){
    if (v.size()<=1){
        return;
    }
    // calculating sizes 
    int n1=(v.size()/2),n2=(v.size() - n1);
    vector<int> temp1(n1),temp2(n2);

    for (int i=0;i<n1;i++){
        temp1[i]=v[i];
    }
    for (int i=0;i<n2;i++){
        temp2[i]=v[i+n1];
    }

    // magic recursion
    merge_sort(temp1);
    merge_sort(temp2);

    array_merger(temp1,temp2,v);
}


int main (){

    vector<int> v={5,6,2,3,9,9,224,46,2,1,31};

    for(int num :v){
        cout<<num<<" ";
    }
    cout<<endl;
    
    merge_sort(v);
    
    for(int num :v){
        cout<<num<<" ";
    }
    cout<<endl;
    
    
    return 0;
}