#include<iostream>
#include<vector>
#include<climits>

using namespace std ;
/*
suppose you are given a array or vector and you have to return the max element in the vector by recursion

*/

int FindMax(vector<int> &v, int start,int Maxelement=INT_MIN){
    if(start==v.size()){
        return Maxelement;
    }

    Maxelement<v[start]?Maxelement=v[start]:Maxelement;

    return FindMax(v,start+1,Maxelement);
}

// alternative way accumulator based ,no need of 3 variables 
// actually in this method we didnt carry the result in each step , instead we first dive deeep and then 
// compare while coming back to

int FindMaxAcc(vector<int> &v,int start){
    if(start==v.size()-1){
        return v[start];
    }

    return max(v[start],FindMax(v,start+1));
}


int main (){

    vector<int> v={1,4,543,4,24,643,365};

    cout<<"\n Max Element is : "<<FindMax(v,0)<<endl;
    
    cout<<"\n Max Element by v2 is : "<<FindMaxAcc(v,0)<<endl;

    return 0;
}