#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    struct Event {
        long double y;
        long double x1, x2;
        int interval_type; // +1 to add interval, -1 remove interval
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;

        // build events
        for (auto &sq : squares) {
            long double x = sq[0];
            long double y = sq[1];
            long double len = sq[2];

            events.push_back({y, x, x + len, +1});
            events.push_back({y + len, x, x + len, -1});
        }

        // Sort by Y
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a.y < b.y;
        });

        // Active x intervals         
        vector<pair<long double, long double>> active;

        multiset<pair<long double, long double>> active;

        auto getUnionWidth = [&]() {
            if (active.empty()) return (long double)0.0;

            vector<pair<long double, long double>> intervals(active.begin(), active.end());
            sort(intervals.begin(), intervals.end());

            long double width = 0;
            long double curL = intervals[0].first;
            long double curR = intervals[0].second;

            for (int i = 1; i < intervals.size(); i++) {
                if (intervals[i].first > curR) {
                    width += curR - curL;
                    curL = intervals[i].first;
                    curR = intervals[i].second;
                } else {
                    curR = max(curR, intervals[i].second);
                }
            }
            width += curR - curL;
            return width;
        };

        // calculate total union area
        long double totalarea = 0;
        for (int i = 0; i < events.size() - 1; i++) {
            auto &e = events[i];

            if (e.interval_type == +1)
                active.insert({e.x1, e.x2});
            else
                active.erase(active.find({e.x1, e.x2}));

            long double height = events[i + 1].y - e.y;
            if (height > 0) {
                totalarea += getUnionWidth() * height;
            }
        }

        long double target = totalarea / 2.0;

        // sweep again to find Y
        active.clear();
        long double currarr = 0;

        for (int i = 0; i < events.size() - 1; i++) {
            auto &e = events[i];

            if (e.interval_type == +1)
                active.insert({e.x1, e.x2});
            else
                active.erase(active.find({e.x1, e.x2}));

            long double height = events[i + 1].y - e.y;
            if (height <= 0) continue;

            long double width = getUnionWidth();
            long double partialarea = width * height;

            if (currarr + partialarea >= target) {
                long double remaining = target - currarr;
                long double miny = e.y + remaining / width;
                return (double)miny;
            }

            currarr += partialarea;
        }

        return 0.0; // usually should never reach
    }
};



int main (){

    
    return 0;
}