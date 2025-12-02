#include<iostream>
using namespace std ;
/*
given a string and a characetr , remove all the occurences of the char from the string 
*/

void charremover(string &mainstring, string &substring, char ch,int i=0){
    if(i==mainstring.size()){
        return;
    }
    if(mainstring[i]!=ch){
        substring.push_back(mainstring[i]);
    }
    charremover(mainstring,substring,ch,i+1);

}


int main (){

    string mainstr="Ayan Awaited Approx five minutes for you ";
    string updatedstr;
    charremover(mainstr,updatedstr,'i');
    cout<<updatedstr;
    return 0;
}