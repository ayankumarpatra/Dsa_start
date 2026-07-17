#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

// failed 1 time 

void mergearr(const vector<int> &arr1, const vector<int> &arr2 , vector<int> & result){
    int idx1=0,idx2=0,resultidx=0;

    while (idx1<arr1.size() && idx2<arr2.size())
    {
        if (arr1[idx1]<arr2[idx2]){
            result[resultidx++]=arr1[idx1];
        }

        else{
            result[resultidx++]=arr2[idx2++];
        }
    }

    while (idx1<arr1.size()){
        result[resultidx++]=arr1[idx1];
    }
    while (idx2<arr2.size()){
        result[resultidx++]=arr2[idx2];
    }
    
}

void mergesort(vector<int> &v){
    if (v.size()<=1){
        return ;
    }

    int p1=v.size()/2;
    int p2=v.size()-p1;

    vector<int> temp1(p1);
    vector<int> temp2(p2);

    for (int i=0;i<p1;i++){
        temp1[i]=v[i];
    }

    for (int i=0;i<p2;i++){
        temp2[i]=v[p1+i];
    }

    mergesort(temp1);
    mergesort(temp2);

    // merge

    mergearr(temp1,temp2,v);
}


int main (){

    vector<int> v={5,6,2,3,9,9,224,46,2,1,31};

    for(int num :v){
        cout<<num<<" ";
    }
    cout<<endl;
    
    mergesort(v);
    
    for(int num :v){
        cout<<num<<" ";
    }
    cout<<endl;

    return 0;
}