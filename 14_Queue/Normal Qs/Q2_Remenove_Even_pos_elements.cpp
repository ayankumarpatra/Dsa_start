/*
Remove all the elements present at even position for a given queue , 

*/

#include<iostream>
#include<queue>

using namespace std ;

void RemoveEvenPosQ(queue<int> &mainq){
    int Qlen=mainq.size(),temp;
    for(int i=0;i<Qlen;i++){
        temp=mainq.front();
        mainq.pop();
        if(i%2!=0){
            mainq.push(temp);
        }
    }
    cout<<"Pos Removal successful \n";
}

int main (){

queue<int> q;

int Queue_len,temp;

cout<<"Enter No of Elments to store in the queue : ";
cin>>Queue_len;

if(Queue_len<=0){
    cout<<"Invalid length, please try again";
    return 0;
}
else {
    cout<<"Enter the elemets \nEnter First Element : ";

}
for(int i=0;i<Queue_len;i++){
    cin>>temp;
    q.push(temp);
    if(i+1!=Queue_len){
        cout<<"\nEnter Next Element : ";
    }
}


    return 0;
}