// find all the permutations of a given string where all the elements are unique 

#include<iostream>
using namespace std ;

void Generate_Permutations (string &mainstring,string &current,vector <bool> &used){

    if(current.size()==mainstring.size()){
        cout<<"["<<current<<"]\n";
        return;
    }

    for(int i=0;i<mainstring.size();i++){
        if(!used[i]){// i mean if the char isnt used yet 

            current.push_back(mainstring[i]);// choose the elemetn as itsnt choosen before 

            used[i]=true;// mark the element as used 

            Generate_Permutations(mainstring,current,used);

            current.pop_back();//backtracking

            used[i]=false;

        }
    }

}

void Permutation_Printer(){

    
}


int main (){

    string mainstr="ABcd";
    string substr;
    
    Generate_Permutations(mainstr,substr,mainstr.size( ),0);

    return 0;
}