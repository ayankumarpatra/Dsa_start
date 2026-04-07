#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Robot {
public:
    int m, n, pos=0;
    bool flag = false;

    Robot(int width, int height) {
        m = width;
        n = height;    
    }
    
    void step(int num) {
        pos = (pos + num) % (2*m + 2*n - 4);

        if(pos == 0) flag = true;
        else flag = false;
    }
    
    vector<int> getPos() {
        if(pos <= m-1) return {pos, 0};
        if(pos <= m-1+n-1) return {m-1, pos-(m-1)};
        if(pos <= 2*(m-1)+n-1) return {2*(m-1)+n-1-pos, n-1};
        else return {0, 2*(n-1)+2*(m-1)-pos};
    }
    
    string getDir() {
        if(pos <= m-1) return flag ? "South" : "East";
        else if(pos <= m-1+n-1) return "North";
        else if(pos <= 2*(m-1)+n-1) return "West";
        else return "South";
    }
};


int main (){

    
    return 0;
}