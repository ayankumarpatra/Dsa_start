// fill array with next greater element , if not found , fill -1
/*
eg if given array 9 1 5 2 3 4 5

o/p = -1 5 -1 3 4 5 -1 

*/

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void FillWithGreaterElements(vector <int> &Main_Vector,vector <int> &Greater_Vect,int Array_size){
    int i=0;
    stack <int> st;

    Greater_Vect[Array_size-i-1]=-1;
    st.push(Main_Vector[Array_size-i-1]);

    for(i=Array_size-2;i>=0;i--){
        while (!st.empty() && Main_Vector[i]>=st.top())
        {
        st.pop();
        }
        if(st.empty()){
            Greater_Vect[i]=-1;
        }
        else {
            Greater_Vect[i]=st.top();
        }

        st.push(Main_Vector[i]);
        
    }

}

void Vector_printer(vector <int> Array,int ArraySize){
    if (Array.size()==0){
        cout<<"Invalid Array to print \n";
        return;
    }
    for (int i=0;i<ArraySize;i++){
        cout<<Array[i]<<" ";
    }
    cout<<endl;
}



int main (){
    int Array_size;
    cout<<"Enter expected number of elements : ";
    cin>>Array_size;
    vector <int> Main_Vector(Array_size);
    vector <int>Greater_Vect(Array_size);
    for (int i=0;i<Array_size;i++){
        cout<<"\nEnter elemnt "<<i+1<<" : ";
        cin>>Main_Vector[i];
    }
    Vector_printer(Main_Vector,Array_size);
    FillWithGreaterElements(Main_Vector,Greater_Vect,Array_size);
    Vector_printer(Greater_Vect,Array_size);
    return 0;
}