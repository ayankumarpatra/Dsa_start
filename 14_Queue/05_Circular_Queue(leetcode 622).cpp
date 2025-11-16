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
    int * arr;
    MyCircularQueue(int k) {
        front=back=0;
        arr=new int[k];
        maxsize=k;
        size=0;
    }
    
    bool enQueue(int value) {//push back
        if(size==maxsize){// size will handle the back=front case 
            return false;
        }
        arr[back]=value;
        back++;
        if(back==maxsize){
            back=0;
        }
        size++;
        return true;
    }
    
    bool deQueue() {//pop front
        if(size==0){
            return false;
        }
        front++;
        if(front==maxsize){
            front=0;
        }
        size--;
        return true;      
    }
    
    int Front() {
        if(size==0){
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if(size==0){
            return -1;
        }
        else if(back==0){
            return arr[maxsize-1];
        }
        return arr[back-1];  
    }
    
    bool isEmpty() {
        if(size==0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(size==maxsize){
            return true;
        }    
        return false;
    }
};

using namespace std ;
int main (){

    
    return 0;
}