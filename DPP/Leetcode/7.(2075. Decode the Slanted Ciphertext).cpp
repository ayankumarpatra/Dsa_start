#include<iostream>
#include<stack>
#include<vector>

using namespace std ;
/*

Not working code 

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        
        if (rows<=1){
            return encodedText;
        }

        int skip=(2*rows)-1,base=0;
        string str="";
        while (base<rows)
        {
            for (int i=0;i<rows;i++){
                if((skip*i)+base<encodedText.length()){
                    str=str+encodedText[(skip*i)+base];
                }
                else {
                    break;
                }
            }
            base++;
        }
        
        while (str.back() == ' ') {
            str.pop_back();
        }
        return str;
    }
};

*/
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        // if there is only one row, no transformation happened
        if (rows <= 1) {
            return encodedText;
        }

        int n = encodedText.length();
        int cols = n / rows;
        string res = "";

        // we iterate through each starting column in the first row
        for (int i = 0; i < cols; i++) {
            // for each start, we move diagonally: (r, c) to (r+1, c+1)
            for (int r = 0, c = i; r < rows && c < cols; r++, c++) {
                // index in the flat string is row * total_cols + current_col
                res += encodedText[r * cols + c];
            }
        }

        // the problem requires removing only trailing spaces
        // we pop characters from the back as long as they are spaces
        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};

int main (){

    
    return 0;
}