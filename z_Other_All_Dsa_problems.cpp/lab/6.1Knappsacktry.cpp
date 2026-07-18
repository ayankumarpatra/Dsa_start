#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

struct item {
    int id , profit , weight;
    double ratio;
};

bool comparator ( item a , item b ){
    return a.ratio>b.ratio;
}

int main (){
    int n=0,cap;
    cout<<"Enter the no of items: ";
    cin>>n;

    vector<item> items(n);

    for (int i=0;i<n;i++){
        cout<<"\nEnter profit of item "<<i<<" : ";
        cin>>items[i].profit;

        cout<<"\nEnter weight of item "<<i<<" : ";
        cin>>items[i].weight;

        items[i].ratio=(items[i].profit*1.0) /items[i].weight;
    }

    cout<<"\nEnter the capacity of the knapsack : ";
    cin>> cap;

    sort(items.begin(),items.end(),comparator);

    double currprofit=0.0;
    double remweight=cap;

    for (int i=0;i<n && remweight>0 ;i++){
        if (items[i].weight<=remweight){
            remweight-=items[i].weight;
            currprofit+=items[i].profit;
            cout<<i<<" fully taken \n";
        }
        else {
            currprofit+=items[i].ratio*remweight;
            remweight=0;
            cout<<i<<" partially taken \n";
        }
    }
    
    cout<<"\nTotal profit : "<<currprofit;

    return 0;
}