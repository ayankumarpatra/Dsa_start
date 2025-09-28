// Remove consecutive duplicates from a string 
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std ;

void ConsecutiveDuplicateRemover(string &str){
    if(str.length()<=1){
        cout<<"\nInvalid string to check for duplicates\n";
        return;
    }
    int elements=str.length();
    stack<char> st;
    int i=0;
    st.push(str[i]);
    for(int i=1;i<elements;i++){
        if(st.top()!=str[i]){
        st.push(str[i]);
        }
    }
    i=0;
    string result="";
    while ((st.size()>0))
    {
        result.push_back(st.top());
        st.pop();
        i++;
    }
    reverse(result.begin(),result.end());
    str=result;
    cout<<"\nSuccessfully removed duplicates\n";

};

int main (){
    string str;
    cout<<"Enter the Sentence : ";
    getline(cin,str);
    cout<<"\nGiven Sentence is : "<<str;
    ConsecutiveDuplicateRemover(str);
    cout<<"\nAfter Removing Given Sentence is : "<<str;

    return 0;
}