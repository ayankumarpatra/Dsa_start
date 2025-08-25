#include<iostream>
using namespace std ;
class student {
public:
    string name;
    int roll;
    float marks;
};  
int main (){
/*
now in the main func if you write student s , 
it will declare a class s , with all the functions inside , like a structure 
*/

student s ; // a student class of name s , like int a is declared 
// now to access the elements , use . operator like s.name="  value ";
// if you print something that isnt assigned yet will print a garbage value 

s.name="Dev";
s.roll=48;
s.marks=89;

cout<<"Name : "<<s.name<<"\nRoll no: "<<s.roll<<"\nMarks obtained : "<<s.marks;
    return 0;
}