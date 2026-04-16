#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//         sort(s.begin(),s.end());
//         int i=0,open=0,close=s.size();

//         while (i<s.size())
//         {
//             if (s[i]=='('){
//                 open++;
//                 close--;
//             }
//             else if (s[i]==')'){
//                 break;
//             }

//             i++;
//         }
//         return abs(open-close);
//     }
// };
// invalid idea to optimize , sorting may break neibouring strings 


//i 2 
// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//         int needclose=0;

//         for (int i=0;i<s.size();i++){
//             if (s[i]=='('){
//                 needclose++;
//             }
//             else{
//                 needclose --;
//             }
//         }

//         return needclose;
//     }
// };

// i3

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;

        for (int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if (s[i]==')'){
                if (!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    st.push(')');
                }
            }
        }
        return st.size();
    }
};

// worked , but trying again the 2nd approach , it should work somehow 

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,close=0;

        for (int i=0;i<s.size();i++){
            if (s[i]=='('){
                open++;
            }
            else if (s[i]==')'){

                if (open>0){
                    open--;
                }
                else {
                close++;
                }
            }
        }
        return (open+close);
    }
};

int main (){

    
    return 0;
}