#include<iostream>
#include<vector>
using namespace std ;

class Queue {
    public :
    int len,front,back,currsize;
    int *Arr;



    Queue(int val){
        if(val<=0){
            cout<<"Invalid size \nPlease Retry\n";
            return;
        }
        len=val;
        front=back=currsize=0;
        Arr=new int [val];
    }

    void push(int val){
        // cases possible 1. overflow 2. insert front 3. insert end 4. insert any pos
    if (currsize>=len){
        cout<<"Queue Full , please retry \n";
        return;
    }
    Arr[back++]=val;
    currsize++;
    cout<<endl;
}

    void pop(){
        if (currsize<0){
            cout<<"Underflow \n";
            return;
        }
        front++;
        currsize--;
        cout<<endl;
    }

    void display(){
        if (currsize<=0){
            cout<<"Empty Queue \n";
            return;
        }

        else{
            for(int i=front;i<back;i++){
                cout<<Arr[i]<<" ";
            }
            cout<<endl;
        }
    }


};


/*
class Queue{

public :
int front,back;
int arr[5];// using totally fixed array or you may use vectors 

// eg 
vector<int> arr;

in constructor 
r

};
*/  

int main (){

    int qlen;
    cout<<"Enter the approx length of the queue you want to create : ";
    cin>>qlen;

    Queue mainq (qlen);

    mainq.display();
    mainq.pop();
    mainq.push(1);
    mainq.push(2);
    mainq.push(3);
    mainq.display();
    mainq.pop();
    mainq.pop();
    mainq.display();
    
    
    return 0;
}

/*

problems in array implementaion of queue

1. wastage of space 

*/