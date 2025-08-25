/*
now to modify a value inside a specific structure , you need to send its addrress , else it will bw send as by reference , 
so value will change but only till that class instance only 
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

void changeby_Val ( student s ){// here datatype classs name is student , like int x 
    s.name="Name changed by change by val\n";
}


void changeby_Ref ( student &s ){// use & here also not like int *x ,as class may not always contain a single value 
    s.name="Name changed by change by refer\n";
}

int main (){

student s ("Dev",48,89);

changeby_Val (s);
cout<<"\nName After change by val: "<<s.name;

changeby_Ref(s);// dont send &s 
cout<<"\nName After change by Ref: "<<s.name;

cout<<"Name : "<<s.name<<"\nRoll no: "<<s.roll<<"\nMarks obtained : "<<s.marks;


/*
o/p is like 
Name After change by val: Dev
Name After change by Ref: Name changed by change by refer
Name : Name changed by change by refer

Roll no: 48
Marks obtained : 89

means by value , name cant changed like array etc fun(arr) send the address , here its not 



if you do like changeby_Val (&s); , then in func , use 

void changeby_Val ( student *s ){
    s->name="Name changed by change by val\n";
}

refer to next lec , we usually dont prefer any one of these , but yes both are correct 
*/
    return 0;
}