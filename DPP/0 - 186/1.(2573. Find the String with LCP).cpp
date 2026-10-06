#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string result(n, ' ');
        char current_char = 'a';

        for (int i = 0; i < n; i++) {
            if (result[i] == ' ') {
                if (current_char > 'z') return ""; 

                result[i] = current_char++;
            }

            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    if (result[j] == ' ')
                        result[j] = result[i];
                    else if (result[j] != result[i])
                        return ""; 

                }
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                int expected = 0;
                if (result[i] == result[j]) {

                    if (i == n - 1 || j == n - 1)
                        expected = 1;
                    else
                        expected = lcp[i + 1][j + 1] + 1;
                }
                if (lcp[i][j] != expected) return ""; 

            }
        }

        return result;
    }
};


int main (){

    
    return 0;
}