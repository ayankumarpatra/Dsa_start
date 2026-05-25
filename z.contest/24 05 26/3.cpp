#include<iostream>
#include<stack>
#include<vector>
#include <string>
#include <unordered_set>


using namespace std;

class Solution {
public:
    int passwordStrength(string password) {
        int strength = 0;
        unordered_set<char> seen;

        for (char c:password) {
            if (seen.count(c)) {
                continue;
            }

            seen.insert(c);

            if (c >='a' && c <='z') {
                strength += 1;
            }
            else if (c >='A' && c <='Z') {
                strength += 2;
            }
            else if (c>='0' && c<= '9') {
                strength +=3;
            }
            else if (c == '!'||c =='@' ||c =='#'|| c =='$') {
                strength += 5;
            }
        }

        return strength;
    }
};


int main (){

    
    return 0;
}