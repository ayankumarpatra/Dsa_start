#include<iostream>
#include<vector>

using namespace std ;

/*

you are given a string , take any character that have multiple occurances in it , now store a new string 
after removing the character
*/

void CharRemover(const string &str,string &tostore,int start,char removechar){
    if (start==str.size()){
        return;
    }

    if(str[start]!=removechar){
        tostore.push_back(str[start]);
        return CharRemover(str,tostore,start+1,removechar);
    }

    if(str[start]==removechar){
        return CharRemover(str,tostore,start+1,removechar);
    }

}

int main (){
    string mainstr="Hello World little lilna ";
    string updatedstr;
    CharRemover(mainstr,updatedstr,0,'l');
    
    cout<<"After Removing updated string is : "<<updatedstr;
    

    return 0;
}
