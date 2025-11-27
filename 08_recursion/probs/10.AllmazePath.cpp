#include<iostream>
using namespace std ;


void GenerateMazePath(int startrow,int startcol,string path){
    
    if(startrow==0 && startcol==0){
        cout<<path<<"End\n";
        return;
    }

    if(startcol>0) {
    GenerateMazePath(startrow,startcol--,path+"right->");
    }

    if(startrow>0) {
    GenerateMazePath(startrow--,startcol,path+"down->");
    }   
}

int main (){

    int row,col;

    cout<<"Enter No of rows : ";
    cin>>row;
    cout<<"Enter No of columns : ";
    cin>>col;
    
    if(col<=0 || row<=0){
        cout<<"Invalid Parameters to generate a maze path \nPlease Retry\n";

        return 0;
    }  


    GenerateMazePath(row-1,col-1,"");

    return 0;
}