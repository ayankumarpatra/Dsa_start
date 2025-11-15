// leetcode 622
/*

front            back 
pop front        push back


*/
#include<iostream>
#include<stack>
#include<vector>

class MyCircularQueue {
public:
    int front,back,maxsize,size;
    bool frontfilled=false;
    int * arr;
    MyCircularQueue(int k) {
        front=back=0;
        int array[k];
        arr=array;
        maxsize=k;
        size=0;
    }
    
    bool enQueue(int value) {//push back
        if(size==maxsize && frontfilled){
            return false;
        }
        else if(!frontfilled){
            if(back>maxsize && front!=0){
                back=0;
                frontfilled=false;
            }
            else if (back<front && front!=0){
                frontfilled=false;
            }
            frontfilled=true;
        }
        if(!frontfilled || (size<maxsize && back<maxsize) ){
            arr[back]=value;
            back++;
            size++;
        }
    }
    
    bool deQueue() {//pop front
        if(size==0){
            return false;
        }
        
    }
    
    int Front() {
        if(size==0){
            return -1;
        }
        return arr[back-1];
    }
    
    int Rear() {
        if(size==0){
            return -1;
        }
        return arr[front];  
    }
    
    bool isEmpty() {
        if(size==0){
            return false;
        }
        return true;
    }
    
    bool isFull() {
        if(front==back){
            return true;
        }    
        return false;
    }
};

using namespace std ;
int main (){

    
    return 0;
}