#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

void maxmin (vector<int> &arr,int low , int high , int &max , int & min){
    if (low==high){// only 1 element 
        max=min=arr[low];
        return;
    }

    else if ( high==low+1){
        if (arr[low]>arr[high]){
            max=arr[low];
            min=arr[high];
        }
        
        else{
            max=arr[high];
            min=arr[low];
        }

        return;
    }

    int mid= (low+high)/2;

    int min1,min2;
    int max1,max2;

    maxmin(arr,low,mid,max1,min1);
    maxmin(arr,mid+1,high,max2,min2);

    max=(max1>max2)? max1:max2;
    min=(min1<min2)? min1:min2;
}



int main (){

    vector<int> arr={5,3,324,3532,21,211};

    int max,min;

    maxmin(arr,0,arr.size()-1,max,min);

    cout<<max<<"  "<<min;
    return 0;
}