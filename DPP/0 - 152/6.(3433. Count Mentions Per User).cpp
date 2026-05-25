#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std ;

class Solution {
public:
    vector<int> countCountions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> Count(numberOfUsers, 0);
        vector<int> timeOn(numberOfUsers, 0);  
        // Track the timestamp when the user is considered online - stress part
        sort(events.begin(), events.end(),
            [](const vector<string>& a, const vector<string>& b) {

                // 1. Compare timestamps if different
                int ta = stoi(a[1]), tb = stoi(b[1]);
                if (ta != tb) return ta < tb;

                // 2. Else If timestamps are equal: OFFLINE events should come before MESSAGE events
                if (a[0] != b[0]) {
                    if (a[0] == "OFFLINE") return true;
                    if (b[0] == "OFFLINE") return false;
                }

                return a[0] < b[0]; 
            }
        );

        for(const vector<string>& x: events){
            if(x[0] == "MESSAGE"){
                // Identify user
                if(x[2] == "ALL"){
                    // For ALL: increCount Countions for everyone, regardless of online/offline state
                    for(int i = 0; i < numberOfUsers; i++){
                        Count[i] ++;
                    }
                }else if(x[2] == "HERE"){
                    // For HERE: increCount Countions only for users currently online
                    for(int i = 0; i < numberOfUsers; i++){
                        // Online means current timestamp >= timeOn[i]
                        if(stoi(x[1]) >= timeOn[i]){
                            timeOn[i] = stoi(x[1]);
                            Count[i] ++;
                        }
                    }
                }else{
                    // Manual Countion: may also Countion offline users
                    string s = x[2];
                    string word;
                    stringstream ss(s);
                    while(ss >> word){
                        // Extract numeric part after "id"
                        int num = stoi(word.substr(2));
                        timeOn[num] = max(stoi(x[1]), timeOn[num]);
                        Count[num] ++;
                    }
                }
            }



            else{ //x[0] == "OFFLINE"
                //Identify user
                if(x[2] == "ALL"){
                    // ALL OFFLINE: mark all users as offline (timestamp + 60)
                    for(int  i = 0; i < numberOfUsers; i++){
                        timeOn[i] = stoi(x[1]) + 60;
                    }
                }else if(x[2] == "HERE"){
                    // Set all currently-online users to OFFLINE
                    // Do not modify users who are already offline
                    for(int i = 0; i < numberOfUsers; i++){
                        if(stoi(x[1]) >= timeOn[i]){
                            timeOn[i] = stoi(x[1]) + 60;
                        }
                    }
                }else{
                    // Manual OFFLINE: mark listed users as offline
                    // Applies even if they were already offline
                    string s = x[2];
                    string word;
                    stringstream ss(s);
                    while (ss >> word) {
                        string digits;
                        for (char c : word)
                            if (isdigit(c)) digits += c;

                        if (!digits.empty()) {
                            int num = stoi(digits);
                            timeOn[num] = stoi(x[1]) + 60;
                            // timeOf[num] = stoi(x[1]);
                        }
                    }
                }
            }
        }

        return Count;
    }
};


int main (){

    
    return 0;
}