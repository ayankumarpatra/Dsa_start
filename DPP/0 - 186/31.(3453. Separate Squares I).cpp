#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

/*
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
    approach supppose 3 square given a , b, c with random x length 3,5,8

    forgetting about the coordinates temporarily 

    now will run a loop that will calculate 

    like first time 
    
    bellow line : 1/2 a len + 1/2 blen + 1/2 clen ....
    above line : 1/2 a len + 1/2 blen + 1/2 clen ....

    if both are approx equal retun 1/2 else continue 2/3, 4/5 .... 

    i just gussed to solve not sure

    // failed idea 
}
};
*/

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        // init total area =0;

        double totalarea=0;
        double low=1e9,high=-1e9;

        // calculating total area and maxy and min y

        for(const auto &sq : squares){
            double tempy=sq[1],len=sq[2];

            totalarea+=len*len;// as square

            low=min(low,tempy);
            high=max(high,tempy+len);
        }

        // now our targetarea = totalarea/2

        double targetarea=totalarea/2;

        // starting binary search

        for (int i=0;i<=60;i++){// 60 iterations will be enough to find the expected precision 

            double mid =(low+high)/2.0;
            double bellowarea=0.0;

            for (const auto & sq : squares){
                double current_y=sq[1],len=sq[2];
                // 
                if (mid<=current_y){
                    continue;// as line is bellow the entire square
                }

                else if (mid>=current_y + len){// as top will be bottom y + len
                    bellowarea+=len*len;
                }
                else {
                    bellowarea+=(mid-current_y)*len;
                }
            }
                if (bellowarea<targetarea){
                    low=mid;
                }
                else {
                    high=mid;
                }
        }

        return low;
    }
};


int main (){

    
    return 0;
}