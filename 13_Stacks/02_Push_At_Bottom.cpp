// push at bottom 
#include<iostream>
#include<stack>
using namespace std ;

    void printstack (stack<int> &st){
        // printed reverse , not as per inserted order 
        stack<int>temp=st;
        while (!temp.empty())
        {
        cout<<temp.top()<<" ";
        temp.pop();
        }
        
    }



int main (){

    stack<int> st;

    int total,element,i=1,pos,temptotal,valtopush;
    cout<<"Enter how many elements you wish to keep into the stack : ";
    cin>>total;
    temptotal=total;
    if(total<=0){
        cout<<"Invalid input ";
    }
    else {
        stack<int>temp1;

        while (temptotal-->0)
        {
        cout<<"Enter element "<<i++<<" : ";
        cin>>element;
        st.push(element);
        }
        
        cout<<"Enter the position : ";
        cin>>pos;
        pos-=1;// to convert it with real life indexing 
        cout<<"\nEnter the value to push : ";
        cin>>valtopush;
    if(pos<0 || pos>total){
        cout<<"invalid position";
        return 1;// we can return 0 to get error free or exit or abort in stlib 
    }
    else if(pos==total){
        st.push(valtopush);
        cout<<"value succesfully inserted ";
        printstack(st);
    }

    else {
        stack<int>tempstack;
        while (pos-->0)
        {
        tempstack.push(st.top());
        st.pop();
        }
        st.push(valtopush);
        while (!tempstack.empty())
        {
        st.push(tempstack.top());
        tempstack.pop();
        }

        printstack(st);
        
    }

    }
    return 0;
}
