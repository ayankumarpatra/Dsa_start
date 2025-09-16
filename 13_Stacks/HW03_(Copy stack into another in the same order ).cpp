// get a stack and copy the same stack as same order to another 


// used direct copy here , we can also do it by using  more stacks if need 


#include<iostream>
#include<stack>
using namespace std ;
int main (){

    stack<int> st;

    int total,element,i=1;
    cout<<"Enter how many elements you wish to keep into the stack : ";
    cin>>total;
    if(total<=0){
        cout<<"Invalid input ";
    }
    else {
        stack<int>temp1;
        while (total-->0)
        {
        cout<<"Enter element "<<i++<<" : ";
        cin>>element;
        st.push(element);
        }
        
       temp1=st;
           
    }
    return 0;
}