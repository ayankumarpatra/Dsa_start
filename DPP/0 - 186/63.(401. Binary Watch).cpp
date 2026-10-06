#include<iostream>
#include<stack>
#include<vector>

using namespace std ;



class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
                vector<string> result;

        // try all hours 0 to 11
        for (int hour = 0; hour < 12; ++hour) {
            // try all minutes 0 to 59
            for (int minute = 0; minute < 60; ++minute) {
                // count how many bits are on in hour and minute
                int hour_bits = __builtin_popcount(hour);
                int minute_bits = __builtin_popcount(minute);

                // if total lit leds equals required turnedon
                if (hour_bits + minute_bits == turnedOn) {
                    // format time with minute as two digits
                    string time_str = to_string(hour) + ":" +
                                      (minute < 10 ? "0" : "") +
                                      to_string(minute);

                    result.push_back(time_str);
                }
            }
        }

        return result;
    
    }
};


int main (){

    
    return 0;
}