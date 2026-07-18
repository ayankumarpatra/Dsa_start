#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

struct job
{
    int profit , deadline;
};

bool comaparator ( job a , job b){
    return a.profit>b.profit;
}


int main (){

    int n=0,maxdeadline;
    cout<<"Enter the no of jobs: ";
    cin>>n;

    vector<job> jobs;

    for (int i=0;i<n;i++){
        cout<<"\nEnter profit of job "<<i<<" : ";
        cin>>jobs[i].profit;
        cout<<"\nEnter deadline of job "<<i<<" : ";
        cin>>jobs[i].deadline;

        maxdeadline=(jobs[i].deadline>maxdeadline)? jobs[i].deadline:maxdeadline;
    }

    sort(jobs.begin(),jobs.end(),comaparator);

    vector<int> finaljobs(maxdeadline,-1);
    int maxprofit=0;

    for (int i=0;i<n;i++){
        int currprofit=jobs[i].profit;

        for (int j=maxdeadline-1;j>=0;j--){
            if (finaljobs[j]==-1){
                finaljobs[j]=currprofit;
                maxprofit+=currprofit;
                break;
            }
        }
    }

    cout<<"Max profit can be done is : "<<maxprofit;

    return 0;
}