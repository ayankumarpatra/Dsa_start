#include<iostream>
#include<vector>
#include<stack>
using namespace std ;


/*

we can calculate next and previous greater or equal array length and add them up

so alternatively we will do check 
1. prev or next smaller element and travarse till we get any smaller element 
    i mean will stop when i get a smaller element than the index height ( keeping the indexes only )

2. before index 0 , think and apply that the value is -1 , and after the last index , index is index+1 , where the smaller element is present 


3. breadth will be nextgreater-prevgreater-1
    and area = length known , 
    so length*breadth(just calculated)

    **my idea , modify formula to nextsmalleridx-prevsmallindex+1, will check later

*/ 


int MaxAreaFinder(vector<int> Main_Vector){
    // first calculating right smaller elements Aray
    if (Main_Vector.size()==0){
        return 0;
    }
    else if (Main_Vector.size()==1){
        return Main_Vector[0];
    }
    stack <int> Right_stack;
    vector<int> Right_Smaller(Main_Vector.size(),0);
    int i;
    for(i=Main_Vector.size()-1;i>=0;i--){
        while (Right_stack.size()>0 && Main_Vector[Right_stack.top()]>=Main_Vector[i])
        {
            Right_stack.pop();
        }
        Right_Smaller[i]=Right_stack.size()==0?Main_Vector.size():Right_stack.top();
        Right_stack.push(i);
        
    }

    // now calculating left smaller elements array and max area both
    // thinking to create a array similarly for left also , but think instead of wasting space , create a
    //temporary element and do work on it , space saved for extra elements 

    int Temp_Arr_Value,Width,Temparea,Maxarea=0;
    stack <int> Left_Smaller_Stack;
    for(i=0;i<Main_Vector.size();i++){
        while (Left_Smaller_Stack.size()>0 && Main_Vector[Left_Smaller_Stack.top()]>=Main_Vector[i])
        {
            Left_Smaller_Stack.pop();
        }
        Temp_Arr_Value=Left_Smaller_Stack.size()==0?-1:Left_Smaller_Stack.top();
        Width=Right_Smaller[i]-Temp_Arr_Value-1;
        Temparea=Width*Main_Vector[i];// width * height in main arr
        Maxarea=Temparea>Maxarea?Temparea:Maxarea;

        Left_Smaller_Stack.push(i);
    }

    return Maxarea;

}

int main (){

    int No_Of_Rectangles;
    cout<<"Enter Approx No of Rectangles : ";
    cin>>No_Of_Rectangles;
    vector <int> Histogram(No_Of_Rectangles);
    
    for(int i=0;i<No_Of_Rectangles;i++){
        cout<<"Enter the element "<<i+1<<" : ";
        cin>>Histogram[i]; 
    }

    return 0;
}