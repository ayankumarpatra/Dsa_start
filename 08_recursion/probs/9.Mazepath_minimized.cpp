#include<iostream>
using namespace std ;


/*
leave the obstracle one as of now , as you can easily do this

teacher said that , but i think for the old obstracle q , i think i  will just initialize the vector row*col , and mark
the corresponding row , cols =0 or -1 and if while moving i got that  i will choose the other way ,
i mean if at down i am getting -1, will choose to move right oly if right isnt -1 , if both -1 from my pos
path is blocked , we cant reach in that way

then have to try another path please correct if i am diverted from solution

now new q teacher give , modifying the same old q  

in the prev generatepath func , think you have to end at end pos of the matrix ,you have to move from start
pos to end pos, eg 1,1 to row,col , can you do this using only 2 parameters

*/



void GenerateMazePath(int startrow,int startcol){

    if(startcol>0) {
        startcol--;
        cout<<"right->";
    }

    if(startrow>0) {
        startrow--;
        cout<<"down->";
    }   


    if(startrow==0 && startcol==0){
        cout<<"End";
        return;
    }

    return GenerateMazePath(startrow,startcol);
}

int main (){

    int row,col;

    cout<<"Enter No of rows : ";
    cin>>row;
    cout<<"Enter No of columns : ";
    cin>>col;
    
    if(col<=0 || row<=0){
        cout<<"Invalid Parameters to generate a maze path \nPlease Retry\n";
        // i checked here as teacher said to use only 2 parameters and as moving start to end 
        // so no need to take start pos manually 
        return 0;
    }  

    /*
    i think i should rotate the matrix , i mean as start pos is always 1 ,1 , so if i change it to end pos 
    and endpos as startpos , i can do it 

    as said startpos is first start but end at endpos of matrix , so i will just pass the endings as starting 
    as starting will be 1,1 surely 

    or we may use 2 vector consist of starting and ending posbut no need 

    implementing the first idea as it will be easier
    */

    GenerateMazePath(row-1,col-1);// i wish to keep the index same as matrix 
    // i mean frist index of mat is not 1,1 its 0,0 so if i have to do anything by matrix later
    // it will be easy , sir said in q , 1,1 to .. so i thought based on that 

    return 0;
}