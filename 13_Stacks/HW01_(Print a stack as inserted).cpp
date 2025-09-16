// print a stack as inserted , keep a stack as it was after inserting , now also print the elements of the stack as insterted 

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
        temp1.push(element);
        }
        
        while (temp1.size()>0)
        {
        temp2.push(temp1.top());
        temp1.pop();
        }

        while (temp2.size()>0)
        {
        cout<<temp2.top()<<" ";
        temp2.pop();
        }
        
        
    }


    return 0;
}
/*

also a alternate similar and simpler version here , without any extra stack

#include <iostream>
#include <stack>
using namespace std;

void printAsInserted(stack<int> &st) {
    if (st.empty()) return;

    int x = st.top(); 
    st.pop();

    printAsInserted(st);

    cout << x << " ";

    st.push(x);
}

int main() {
    stack<int> st;
    int total, element, i = 1;

    cout << "Enter how many elements you wish to keep into the stack : ";
    cin >> total;

    if (total <= 0) {
        cout << "Invalid input";
    } else {
        while (total-- > 0) {
            cout << "Enter element " << i++ << " : ";
            cin >> element;
            st.push(element);
        }

        cout << "\nStack elements (as inserted): ";
        printAsInserted(st);
        cout << endl;

        cout << "Stack size after printing (unchanged): " << st.size() << endl;
    }
    return 0;
}




*/