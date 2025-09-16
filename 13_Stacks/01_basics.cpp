   #include<iostream>
   #include<stack>
   using namespace std ;
   int main (){
   
    stack<int> st;
    cout<<"size is "<<st.size()<<endl;
    
    st.push(10);
    st.push(20);
    st.push(30);
    
    cout<<"size is "<<st.size()<<endl;
    st.pop();
    cout<<"After pop size is "<<st.size()<<endl;
    
    cout<<"Top element is : "<<st.top()<<endl;
    
    st.push(30);
    st.push(40);
    st.push(50);
    // how to print the stack 

    // while (st.size()>0){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    // but stack become empty 
    
    // how to get the elements back 
    stack <int> temp;
        while (st.size()>0){
            cout<<st.top()<<" ";
            temp.push(st.top());// copying the element to a temp stack 
            st.pop();
        }


        while (temp.size()>0)
        {
        st.push(temp.top());
        temp.pop();
        }
        cout<<"\nsize is "<<temp.size()<<st.size()<<endl;
       return 0;
};