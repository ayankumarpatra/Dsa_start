#include<iostream>
using namespace std ;

class Stack {
    public :
    int arr[5];
    int idx=-1;

    void push(int val){
        if(idx>=5){
            cout<<"Array is full , cant insert new item \n";
            return;
        }
        idx++;
        arr[idx]=val;
        cout<<"Pushed successfully \n";//<<arr[idx]<<endl;
    }

    void pop(){
        if(idx<0){
            cout<<"Empty Array , cant pop \n";
            return;
        }
        idx--;
        cout<<"poped sucessfully \n";
    }

    int top(){
        if(idx<0){
            cout<<"Empty Array , cant get element \n";
            return -1;
        }
        return arr[idx];
    }

    int size(){
        return idx+1;
    }

    void Display(){
        if(idx==-1){
            cout<<"stack is empty\n";
            return;
        }
        cout<<"Elements are : \n";
        for (int i=idx;i>=0;i--)
        {
        cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


};

int main (){

    Stack st;
    cout<<"Size is : "<<st.size()<<endl;
    st.push(10);
    st.Display();
    
    cout<<"Size is : " <<st.size()<<endl;
    st.push(20);
    st.Display();

    return 0;
}