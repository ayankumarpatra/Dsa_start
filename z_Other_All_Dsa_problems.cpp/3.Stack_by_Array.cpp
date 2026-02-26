#include<iostream>
#include<vector>
#include<climits>

using namespace std ;


class stack{
    public:
    int arr[5];
    int idx=-1;

    void push(int val){
        if (idx>=5){
            cout<<"stack is already full ! \n";
            return;
        }
        idx++;
        arr[idx]=val;
    }
    void pop(){
        if (idx>-1){
            idx--;
        }
        else {
            cout<<"Empty Stack \n";
        }
    }
    
    int top(){
        if (idx>-1){
            return arr[idx];
        }
        else {
            cout<<"Empty Stack \n";
            return INT_MIN;
        }

    }
};

int main (){

    stack st;

    int choice=1234,temp=0;

    while (choice!=0)
    {
        cout<<"\n Here Are the available options : 0.Exit 1.push \n2.pop 3.top \nEnter your choice";
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter variable to push : ";
            cin>>temp;
            st.push(temp);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            cout<<st.top()<<endl;
            break;
        case 0:
            break;;
        default:
            break;
        }


    }
    


    
    return 0;
}