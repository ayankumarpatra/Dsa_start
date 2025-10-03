#include<iostream>
using namespace std ;
//bruteforce soln 

int LargestRectangleFinder(int Histogram[],int No_Of_Rectangles){
    int i,j,count,highest=0,temphigher=0;
    for(i=0;i<No_Of_Rectangles;i++){
        j=0;
        count=0;
        while(j<No_Of_Rectangles && Histogram[j]>=Histogram[i]){
           count++;
           j++;
        }
        temphigher=count*Histogram[i];
        if(temphigher>highest){
            highest=temphigher;
        }
    }
    return highest;
}

int main (){
    int No_Of_Rectangles;
    cout<<"Enter Approx No of Rectangles : ";
    cin>>No_Of_Rectangles;
    int Histogram[No_Of_Rectangles];
    for(int i=0;i<No_Of_Rectangles;i++){
        cout<<"Enter the element "<<i+1<<" : ";
        cin>>Histogram[i]; 
    }

    cout<<"\nMax Rectangle possible is : "<<LargestRectangleFinder(Histogram,No_Of_Rectangles);
        
    return 0;
}