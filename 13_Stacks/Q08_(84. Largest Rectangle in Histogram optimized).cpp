#include<iostream>
#include<vector>
#include<stack>
using namespace std ;


/*

calculate next and previous greater or equal array length and add them up

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
    vector <int> MaxPossibleArea;
    vector <int> PrevGreater;
    vector <int> NextGreater;
    int Maxchecker,Minchecker,MaxArea,Vector_size=Main_Vector.size(),Element_Counter;
    stack <int> Maxstack , MinStack;
    Maxstack.push(Main_Vector[Vector_size-1]);
        for (int i=1;i<Main_Vector.size();i++){
            Maxchecker=Vector_size-i-1;
            Minchecker=i;
            Element_Counter=0;

        while (!Maxstack.empty() && Maxchecker!=i && Maxstack.top()<=Main_Vector[i])
        {
        Maxstack.pop();
        Element_Counter++;
        }
        
                    

            
        }

        NextGreater[Vector_size-1]=0;// No max element possible after the last index 
        PrevGreater[0]=0;//No previous greater possible 
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