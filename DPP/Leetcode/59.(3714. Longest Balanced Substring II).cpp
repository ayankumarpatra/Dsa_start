#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        if (n == 0) return 0;

        // best length found so far
        int best_len = 1;

        // 1) handle longest run of same character (e.g. "aaaa")

        int current_run = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                ++current_run;
                best_len = max(best_len, current_run);
            } else {
                current_run = 1;
            }
        }

        // 2) helper for two-letter windows: use prefix balance and first-seen map
        //    we treat ch_pos as +1, ch_neg as -1; other letters reset state

        auto solve_pair = [&](char ch_pos, char ch_neg) {
            int balance = 0; // current prefix difference (ch_pos - ch_neg)
            unordered_map<int,int> first_index;
            // balance 0 is considered seen before start at index -1
            first_index[0] = -1;

            for (int i = 0; i < n; ++i) {
                if (s[i] == ch_pos) {
                    ++balance;
                } else if (s[i] == ch_neg) {
                    --balance;
                } else {
                    // a different character appears: reset map and balance,
                    // treat next index as fresh start (so set first_index[0] = i)
                    first_index.clear();
                    first_index[0] = i;
                    balance = 0;
                    continue;
                }

                // if seen this balance before, candidate length = i - first_index[balance]
                if (first_index.count(balance)) {
                    best_len = max(best_len, i - first_index[balance]);
                } else {
                    // record first occurrence of this balance
                    first_index[balance] = i;
                }
            }
        };

        // run the pair-solver for the three ordered pairs used by the original solution
        solve_pair('a', 'b');
        solve_pair('b', 'c');
        solve_pair('c', 'a');


        // handle substrings that may contain all three letters
        // use pair of differences (freq[b]-freq[a], freq[c]-freq[a])
        // if the pair of differences repeats, the interval between repeats
        // is balanced with respect to relative counts.

        map<pair<int,int>, int> first_pair_index;
        first_pair_index[{0, 0}] = -1; // initial state before any character

        int freq[3] = {0, 0, 0}; // freq for 'a','b','c'
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if (0 <= idx && idx < 3) ++freq[idx];
            // compute differences relative to freq[a]
            int diff_b_a = freq[1] - freq[0];
            int diff_c_a = freq[2] - freq[0];
            pair<int,int> key = {diff_b_a, diff_c_a};

            if (first_pair_index.count(key)) {
                best_len = max(best_len, i - first_pair_index[key]);
            } else {
                // store first index where this (diff_b_a, diff_c_a) occurs
                first_pair_index[key] = i;
            }
        }

        return best_len;
    }
};



int main (){

    
    return 0;
}