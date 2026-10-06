#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());

        double currmass=mass;
        for (int i=0;i<asteroids.size();i++){
            if (currmass>asteroids[i]){
                currmass+=asteroids[i];
            }
            else{
                return false;
            }
        }

        return true;
    }
};


int main (){

    
    return 0;
}