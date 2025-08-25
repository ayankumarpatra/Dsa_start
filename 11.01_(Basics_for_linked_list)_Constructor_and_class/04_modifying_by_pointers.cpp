/*
prev lec , 03_ modify... we discussed about normal pointers , now will move on to advanced pointers 
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
student *ptr=&s;// created a pointer that points towards s 

cout<<"\nName Before change: "<<s.name<<endl;

//(*ptr).name="Raghav";// must give (*ptr) , dont give only *ptr , as its not a primitive datatype
// alternatively you can write 

ptr->name="Hello world";
cout<<"\nName After change by val: "<<s.name<<endl;

/*
Name Before change: Dev

Name After change by val: Raghav

so name is changed 

// alternatively if you  are sending via a func , you can write only ..
// func(&s)// also valid , done in 03 as i am doing experiment 
*/

cout<<"Name : "<<s.name<<"\nRoll no: "<<s.roll<<"\nMarks obtained : "<<s.marks;

    return 0;
}