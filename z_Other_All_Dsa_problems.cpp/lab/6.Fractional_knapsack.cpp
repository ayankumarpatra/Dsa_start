#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>

using namespace std ;

struct item
{
    double profit,weight,ratio;
};

bool comparator(item a,item b){
    return a.ratio>b.ratio;
}

int main (){

    int n;
    cout<<"Enter the no of elements : ";
    cin>>n;
    
    vector<item> items(n);
    
    for (int i=0;i<n;i++){
        cout<<"\nEnter the profit of element"<<i+1<<" ";
        cin>>items[i].profit;
        cout<<"Enter the weight of element"<<i+1<<" ";
        cin>>items[i].weight;
        
        items[i].ratio=items[i].profit/items[i].weight;
    }
    
    sort(items.begin(),items.end(),comparator);

    double weight;
    cout<<"Enter Weight of the bag : ";
    cin>>weight;
    int i=0;

    while (weight>0)
    {
        if (items[i].weight>=weight){
            weight-=items[i].weight;
            cout<<"Weight "<<items[i].weight<<"Taken Fully \n Remaining Weight ="<<weight<<endl;
        }
        else{
            
            cout<<"Weight "<<items[i].weight<<"Taken partially : "<< items[i].ratio*weight<<"\n Remaining Weight ="<<0<<endl;
            weight=0;
        }
        i++;
    }
    

    return 0;
}