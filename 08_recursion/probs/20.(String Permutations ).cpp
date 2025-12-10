// find all the permutations of a given string where all the elements are unique 

#include<iostream>
#include<vector>
using namespace std ;

void Generate_Permutations (string mainstring,string substring){
    if(mainstring==""){
        cout<<substring<<endl;
        return;
    }

    for (int i=0;i<mainstring.length();i++){
        char ch = mainstring[i];
        string left=mainstring.substr(0,i);
        string right=mainstring.substr(i+1);// automatically will take , str size by default 

        Generate_Permutations(substring+ch,left+right);
    }

}



int main (){

    string mainstr="ABcd";
    string substr;
    
    Generate_Permutations(mainstr,substr);

    return 0;
}