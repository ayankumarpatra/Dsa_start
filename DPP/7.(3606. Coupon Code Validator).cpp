#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std ;


class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        int n = code.size();

        // custom order mapping
        unordered_map<string, int> order = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        // buckets for the 4 groups
        vector<vector<string>> buckets(4);

        // check each coupon
        for (int i = 0; i < n; i++) {

            // 1) check code validity
            if (code[i].empty()) continue;

            bool ok = true;
            for (char c : code[i]) {
                if (!(isalnum(c) || c == '_')) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            // 2) check businessLine validity
            if (!order.count(businessLine[i])) continue;

            // 3) check active
            if (!isActive[i]) continue;

            // If valid then put into correct bucket by businessLine
            int idx = order[businessLine[i]];
            buckets[idx].push_back(code[i]);
        }

        // sort codes inside each category
        for (auto &b : buckets) {
            sort(b.begin(), b.end());
        }

        // combine result
        vector<string> result;
        for (auto &b : buckets) {
            for (auto &s : b) {
                result.push_back(s);
            }
        }

        return result;
    }
};


int main (){

    
    return 0;
}