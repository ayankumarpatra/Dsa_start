#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

struct job{
    char id;
    int profit,deadline;
};

bool comparator(job a ,job b){
    return a.profit>b.profit;
}

int main (){
int n;

cout<<"Enter number of jobs : ";
cin>>n;

vector<job> jobs(n); 
int maxdeadline=0;

for (int i=0;i<n;i++){
    cout<<"Enter job id for "<<i+1<<" Job : ";
    cin>>jobs[i].id;
    
    cout<<"Enter proit for "<<i+1<<" Job : ";
    cin>>jobs[i].profit;

    cout<<"Enter Deadline for "<<i+1<<" Job : ";
    cin>>jobs[i].deadline;

    if (jobs[i].deadline>maxdeadline){
        maxdeadline=jobs[i].deadline;
    }
}

    sort(jobs.begin() , jobs.end(),comparator);

    int maxprofit=0,jobcount=0;
    vector<char> profitids(maxdeadline+1,' ');

    for (int i=0;i<n;i++){
        for (int j=jobs[i].deadline;j>0;j--){
            if (profitids[j]==' '){
                maxprofit+=jobs[i].profit;
                profitids[j]=jobs[i].id;
                jobcount++;
                break;
            }
        }
    }

    cout<<"total jobs done "<<jobcount<<endl;
    cout<<"total profit done "<<maxprofit<<endl;

    
    return 0;
}