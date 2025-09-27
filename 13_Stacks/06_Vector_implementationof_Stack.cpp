#include<iostream>
#include<vector>
using namespace std ;


class Stack {
    vector <int> v;

    void push (int val){
        v.push_back(val);// no overflow condition in vector 
    }

    void pop(){
        if(v.size()==0){
            cout<<"Empty vector , cant pop\n";
            return;
        }
        v.pop_back(); 
    }


    int top(){
        if(v.size()==0){
            cout<<"Empty vector , cant get top elemet \n";
            return -1;
        }
    
        return v[v.size()-1];
        
    }

    int size (){
        return v.size()+1;
    }
};

int main (){

    return 0;
}