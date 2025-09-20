#include<iostream>
#include<stack>
// push pop size 
using namespace std;

void DisplayStackNormal(stack<int> *st){
    stack<int>temp;
    while (st->size()>0)
    {
    cout<<st->top()<<" ";
    temp.push(st->top());
    st->pop();
    }
    while (temp.size()>0)
    {
    st->push(temp.top());
    temp.pop();
    }
    
}

void DisplayStackByRecursion(stack<int> *st){
    if(st->size()==0) return;
    int x= st->top();
    // cout<<x<<" "; if give here will print lifo , normally 
    st->pop();
    DisplayStackByRecursion(st);
    cout<<x<<" ";// printing revese 
    st->push(x);
}

int main(){

stack <int> st;
int terms,val,i=1;
cout<<"Enter number of terms you want to add in stack : ";
cin>>terms;
while (terms-->0)
{
cout<<"Enter the element "<<i++<<": ";
cin>>val;
st.push(val);
}

DisplayStackNormal(&st);
cout<<endl;
DisplayStackByRecursion(&st);

    return 0;
}