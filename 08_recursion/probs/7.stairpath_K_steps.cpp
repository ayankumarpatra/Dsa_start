#include<iostream>

using namespace std ;
/*

a person is starting from ground , theres n no of stairs (take user in) , the person can move max k steps at a time , at a single step 
return the number of combinations possible to reach the top from ground

*/
int StairPathComb(int length, int steps){

    if(length==0){return 1;}
    if(length<0){return 0;}

    int totalcombo=0;

    for(int i=1;i<=steps;i++){
        totalcombo+=StairPathComb(length-i,steps);
    }

    return totalcombo;
}


int main (){

    int Stairs,steps;
    cout<<"Enter No of stairs : ";
    cin>>Stairs;

    cout<<"Enter No of Steps : ";
    cin>>steps;

    if(Stairs<=0){
        cout<<"Invalid input please try again \n";
        return 0;
    }

    cout<<"No of ways we can get into top is : "<<StairPathComb(Stairs,steps);
    return 0;
}