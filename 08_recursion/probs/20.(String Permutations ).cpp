// find all the permutations of a given string where all the elements are unique 

#include<iostream>
using namespace std ;

void Permutation_print_helper (string &mainstring,string &substring,int length,int i=0){
    if(i==mainstring.length()){
    if(substring.length()==length){
        cout<<"[";
            for (char ch : substring){
                cout<<ch<<" ";
            }
        cout<<"]\n";
    }
        return;
    }
    // adding the current element 
    substring.push_back(mainstring[i]);
    Permutation_print_helper(mainstring,substring,length,i+1);
    
    substring.pop_back();
    Permutation_print_helper(mainstring,substring,length,i+1);

}

void Permutation_Printer(){

    
}


int main (){

    string mainstr="ABcd";
    string substr;
    
    Permutation_print_helper(mainstr,substr,mainstr.size( ),0);

    return 0;
}