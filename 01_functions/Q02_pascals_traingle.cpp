#include<iostream>
using namespace std ;
/*
logic row number c column number 
*/

// Hi Dev , didnt handelled edge cases as in factorial and ncr functions as i know i  will be passing the row and column nums
    
int Factorial_Value(int n){
    if (n==0 || n==1)
        return 1;
    else {
        return n*Factorial_Value(n-1);
    }
}
int ncr_Value (int n , int r){
    if (n==r)
        return 1;
    else 
        return Factorial_Value(n)/(Factorial_Value(r)*Factorial_Value(n-r));
}

void PrintPascal_Traingle (int lines){
    int row,col;
    for (row=0;row<=lines;row++){
        int spaces=lines-row-1;
                while((spaces--)>0)
                    cout<<" ";
        for (col=0;col<=row;col++){
            cout<<ncr_Value(row,col)<<" "; 
        }
    cout<<"1\n";
    }
}
int main (){
int lines ;
cout<<"Enter number of lines : ";
cin>>lines;

PrintPascal_Traingle (lines);
    return 0;
}

/*
alternate version with basic math formula and no recursion or fact calculation 
also added edge case handling 
val=val×(row−col​)/(col+1)


#include <iostream>
using namespace std;

void printPascalTriangle(int lines) {
    if (lines < 0) {
        cout << "Invalid number of lines.\n";
        return;
    }

    for (int row = 0; row <= lines; row++) {
        // Print spaces for alignment
        for (int spaces = 0; spaces < lines - row; spaces++)
            cout << " ";

        int val = 1; // First value in every row is 1
        for (int col = 0; col <= row; col++) {
            cout << val << " ";
            // Calculate next value in row without factorials
            val = val * (row - col) / (col + 1);
        }
        cout << "\n";
    }
}

int main() {
    int lines;
    cout << "Enter number of lines: ";
    cin >> lines;

    printPascalTriangle(lines);

    return 0;
}


or shortly optimized as 


// base code without spaces ;
#include<iostream>
using namespace std ;
int main (){
    int n;
    cout<<"Enter no of lines : ";
    cin>>n;
    for (int i=0;i<n;i++){
        int curr =1;
        for (int j=0;j<=i;j++){
            cout<<curr<<" ";
            curr=(i-j)/(j+1);
        }
        cout<<endl;
    }
    return 0;
}
added spaces
*/
#include<iostream>
using namespace std ;
int main (){
    int n;
    cout<<"Enter no of lines : ";
    cin>>n;
    for (int i=0;i<n;i++){
        int curr =1,spaces=n-i;
        while(spaces-->0)
            cout<<" ";
        for (int j=0;j<=i;j++){
            cout<<curr<<" ";
            curr=curr*(i-j)/(j+1);
        }
        cout<<endl;
    }
    return 0;
}