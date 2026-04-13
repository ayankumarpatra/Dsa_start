#include<iostream>
#include<string>
#include<algorithm>
#include<climits>

using namespace std ;


class Solution {
public:
    int reverse(int x) {
        bool isnegetive=false;
        long long temp=x;
        if (x<0){
            isnegetive=true;
            temp=temp*-1;
        }

        string num=to_string(temp);

        std:: reverse(num.begin(),num.end());

        if (isnegetive){
            temp= stoll(num)*-1;
        }
        else {
            temp= stoll(num);
        }

        if (temp>INT_MAX || temp<INT_MIN){
            return 0;
        }
        return (int(temp));
    }
};

int main (){

    
    return 0;
}