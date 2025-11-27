#include<iostream>
using namespace std ;


/*
A tough q , just for you , as you cracked prev q as fibonnachi 

take a maze(matrix) of user input size eg 5*4

take input of starting and ending pos like start from (0,0) end at (4,3) 

remember 1. you can only move left to right and up to down only , cant move back to up or move right to left 
2. print the path you choose , eg start -> right -> down ... -> end 

no need to choose shorten path , or use dp etc , you havent learned it yet , solve it by recursion only 

do this if you can , then will give you obstracle in btn
*/



void GenerateMazePath(int row,int col, int startrow,int startcol,int endrow,int endcol ){

    if(startcol>endcol || startrow>endrow || endrow>row || endcol>col){
        cout<<"Invalid Parameters to generate a maze path \nPlease Retry\n";
        return;
    }

    // moving left to right 

    if(startcol<endcol) {
        startcol++;
        cout<<"right->";
    }

    if(startrow<endrow) {
        startrow++;
        cout<<"down->";
    }   


    if(startrow==endrow && startcol==endcol){
        cout<<"End";
        return;
    }

    return GenerateMazePath(row,col,startrow,startcol,endrow,endcol);
}

int main (){

    int row,col,startrow,startcol,endrow,endcol;

    cout<<"Enter No of rows : ";
    cin>>row;
    cout<<"Enter No of columns : ";
    cin>>col;
    
    cout<<"Enter starting coordinates (startrow )  : ";
    cin>>startrow;
    cout<<"Enter starting coordinates (startcol )  : ";
    cin>>startcol;
    
    cout<<"Enter ending row (endrow )  : ";
    cin>>endrow;
    cout<<"Enter ending col (endcol )  : ";
    cin>>endcol;


    GenerateMazePath(row,col,startrow,startcol,endrow,endcol);

    return 0;
}