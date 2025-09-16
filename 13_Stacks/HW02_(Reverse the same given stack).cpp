// get a stack and reverse the stack 

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
        stack<int>temp2;

        while (total-->0)
        {
        cout<<"Enter element "<<i++<<" : ";
        cin>>element;
        st.push(element);
        }
        
        while (st.size()>0)
        {
        temp1.push(st.top());
        st.pop();
        }

        while (temp1.size()>0)
        {
        temp2.push(temp1.top());
        cout<<temp1.top()<<" ";// actually its not stored in st , but finally this same thing should be in st 
        temp1.pop();
        }

        while (temp2.size()>0)
        {
        st.push(temp2.top());
        temp2.pop();
        }
           
    }
    return 0;
}



/*


#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st, temp;
    int total, element, i=1;

    cout << "Enter how many elements you wish to keep into the stack: ";
    cin >> total;

    for (int j=0; j<total; j++) {
        cout << "Enter element " << i++ << ": ";
        cin >> element;
        st.push(element);
    }

    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    while (!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }

    cout << "\nReversed stack (top to bottom): ";
    stack<int> copy = st;// we can just do this copy , its valid 
    while (!copy.empty()) {
        cout << copy.top() << " ";
        copy.pop();
    }
    cout << endl;

    return 0;
}


*/