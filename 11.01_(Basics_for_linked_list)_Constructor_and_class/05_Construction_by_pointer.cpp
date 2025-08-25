
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
student *s  = new student("Dev",48,89);
/*       student *s  =       new                             student("Dev",48,89);
         ^ this student      ^ this new is a memory             ^ this is the student constructor call 
is a pointer that points     allocation operator like
to the student class         malloc here used to
                            alocate memory for the 
                            student class (next student) 


*/

// now if class is initialized by pointers , to print a element , have to use -> operator (this op )

cout<<"Name : "<<s->name<<"\nRoll no: "<<s->roll<<"\nMarks obtained : "<<s->marks;

    return 0;
}