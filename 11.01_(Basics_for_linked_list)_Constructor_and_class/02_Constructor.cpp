/*
in old code we have donr like 
class student {
public:
    string name;
    int roll;
    float marks;
};
int main (){

student s;

s.name="Dev";// assigned the value like this .. but lets move on 
s.roll=48;
s.marks=89;
*/

#include<iostream>
using namespace std ;
class student {
public:
    string name;
    int roll;
    float marks;

    student (string str , int rol, float mark){
        name = str;
        roll=rol;
        marks=mark;
    }
};
int main (){

student s ("Dev",48,89);
// just like a function , but assign values to the class structure after creating a student s 
cout<<"Name : "<<s.name<<"\nRoll no: "<<s.roll<<"\nMarks obtained : "<<s.marks;
    return 0;
}

/*
but note in the constructor 

    student (string str , int rol, float mark){
        name = str;
        roll=rol;
        marks=mark;
    } if you assign diff names its okay no problem , but if the name is same  you have to use this-> eg 

        student (string name , int roll, float marks){
        this->name = name;
        // refer to lecture 4 , its actually a dereferencing pointer , eg its actually 
        (*name)=name;// *name is the structures name , which will be change , rhs name is current name 
        this->roll=roll;
        this->marks=marks;
    }

*/