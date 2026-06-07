#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

struct item {
    int profit ,weight,ratio;
};

bool compareitems(item a , item b){
    return a.ratio>b.ratio;
}

int main (){

    int n;
    cout<<"Enter No of items : ";
    cin>>n;

    vector<item> items(n);
    
    for (int i=0;i<n;i++){
        cout<<"\nEnter profit of item "<<i+1<<" : ";
        cin>>items[i].profit;

        cout<<"\nEnter weight of item "<<i+1<<" : ";
        cin>>items[i].weight;

        items[i].ratio=items[i].profit/items[i].weight;

    }

    sort(items.begin(),items.end(),compareitems);

    int capacity;

    cout<<"Enter Bag capacity ";
    cin>>capacity;

    double currprofit=0.0,remweight=capacity;

    for (int i=0; i<n && remweight>0;i++)
    {
        if (remweight>=items[i].weight){
            remweight-=items[i].weight;
            currprofit+=items[i].profit;
        }

        else {
            currprofit+=items[i].ratio*remweight;
            remweight=0;
        }
    }

    cout<<"Total Profit  "<<currprofit;
    
    
    return 0;
}