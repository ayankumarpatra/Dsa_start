#include<iostream>
#include<vector>
#include<stack>
using namespace std ;





int MaxAreaFinder(vector<int> Main_Vector){
    // first lets create the right smaller elements index array
    stack <int> Right_Smaller_Stack;
    vector <int> Right_Smaller_Index_Array(Main_Vector.size(),0);
    int i,Vector_Size=Main_Vector.size();
    for(i=Vector_Size-1;i>=0;i--){
        while (Right_Smaller_Stack.size()>0 && Main_Vector[Right_Smaller_Stack.top()]>=Main_Vector[i])
        {
            Right_Smaller_Stack.pop();
        }
        Right_Smaller_Index_Array[i]=Right_Smaller_Stack.size()==0?Vector_Size:Right_Smaller_Stack.top();
        Right_Smaller_Stack.push(i);
        
    }


    // now create instead creating left smaller element array , just claculating and returning max 
    int Temp_LeftArr,Width,TempArea,MaxArea=0; 
    stack <int> Left_Smaller_Stack;
    for(i=0;i<Vector_Size;i++){
        while (Left_Smaller_Stack.size()>0 && Main_Vector[Left_Smaller_Stack.top()]>=Main_Vector[i])
        {
        Left_Smaller_Stack.pop();
        }

        Temp_LeftArr=Left_Smaller_Stack.size()==0?-1:Left_Smaller_Stack.top();

        Width=Right_Smaller_Index_Array[i]-Temp_LeftArr-1;
        TempArea=Width*Main_Vector[i];
        MaxArea=MaxArea>TempArea?MaxArea:TempArea;
        Left_Smaller_Stack.push(i);
    }

    return MaxArea;

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