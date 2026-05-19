#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string sortVowels(string s) {
        vector<int> freq(256, 0);
        vector<int> first_pos(256, -1);
        vector<char> vowels;

        for (int i = 0; i < s.size(); ++i) {
            if (isVowel(s[i])) {
                freq[s[i]]++;
                if (first_pos[s[i]] == -1) {
                    first_pos[s[i]] = i;
                }
                vowels.push_back(s[i]);
            }
        }

        sort(vowels.begin(), vowels.end(), [&](char a, char b) {
            if (freq[a] != freq[b]) {
                return freq[a] > freq[b];
            }
            return first_pos[a] < first_pos[b];
        });

        int idx = 0;
        string result = s;
        for (int i = 0; i < result.size(); ++i) {
            if (isVowel(result[i])) {
                result[i] = vowels[idx++];
            }
        }

        return result;
    }
};

int main (){

    
    return 0;
}