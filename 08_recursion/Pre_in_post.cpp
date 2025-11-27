#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

/*

if in a recursive func , the structure look like 

work        // this is known as pre 
func call 1
work        // this is known as in 
func call 2
work        // this is known as post 


output also differs , eg
*/

void Pre_in_Post(int n){
        if(n==8){
            return;
        }
    cout<<"Pre : "<<n<<endl;// pre work
    Pre_in_Post(n+1);// func call 1
    cout<<"in : "<<n<<endl;// in work
    Pre_in_Post(n+1);// func call 2
    cout<<"post : "<<n<<endl;// post work
}


int main (){

 Pre_in_Post(5);

    return 0;
}