#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>

using namespace std ;


class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int pos=INT_MAX,front=0,back=0;

        for (int i=0;i<words.size();i++){
            if (words[i]==target){
                pos=i;
                front=(i-startIndex+words.size())%words.size();
                back=(words.size()+i-1)%words.size();
                break;
            }
        }
        if (pos==-1){
            return -1;
        }
        if (pos==startIndex){
            return 0;
        }

        else {
            return min(front,back);
        }
    }
};


//p2

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int pos=INT_MAX,front=0,back=0;
        bool present=false;

        for (int i=0;i<words.size();i++){

        if (words[i]==target){
                present=true;
                front=((i-startIndex+words.size())%words.size());
                front=abs(front);
                back=words.size()-front;
                back=abs(back);
                pos=min(pos,min(front,back));
            }
        }
        if (!present){
            return -1;
        }

        else {
            return pos;
        }
    }
};

int main (){

    
    return 0;
}