#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long, int> m;

        for (int num : nums) {
            m[num]++;
        }

        int ans = 1;

        if (m.count(1)) {
            int f = m[1];
            if (f % 2 == 0)
                ans = max(ans, f - 1);
            else
                ans = max(ans, f);
        }

        vector<long long> keys;
        for (auto &it : m) {
            keys.push_back(it.first);
        }

        for (long long cur : keys) {

            if (cur == 1)
                continue;

            long long tem = cur;
            int len = 0;

            while (true) {

                if (!m.count(tem) || m[tem] < 2)
                    break;

                len += 2;
                tem = tem * tem;
            }

            if (m.count(tem) && m[tem] == 1)
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};

int main (){

    
    return 0;
}