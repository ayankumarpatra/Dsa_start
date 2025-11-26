#include<iostream>

using namespace std ;
/*

a person is starting from ground , theres n no of stairs (take user in) , the person can move min 1 or max 2 steps at a time , at a single step 
return the number of combinations possible to reach the top from ground

*/
int StairPathComb(int length){// it will be like a fibonaachi series 

    if(length==2){ return 2;}
    if(length==1){ return 1;}

    return StairPathComb(length-1)+StairPathComb(length-2);
}


int main (){

    int Stairs;
    cout<<"Enter No of stairs : ";
    cin>>Stairs;

    if(Stairs<=0){
        cout<<"Invalid input please try again \n";
        return 0;
    }

    cout<<"No of ways we can get into top is : "<<StairPathComb(Stairs);
    return 0;
}