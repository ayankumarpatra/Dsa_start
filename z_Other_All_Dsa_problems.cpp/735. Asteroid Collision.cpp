#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int> returnvect;

        int curr_asteroid;

        for ( auto curr_asteroid1 : asteroids ){
            curr_asteroid = curr_asteroid1;
            if ( returnvect.empty() || // if the vector is empty 
            (curr_asteroid > 0 && returnvect.back() > 0 ) || // if curr stone and the last stone , both positive
            (curr_asteroid < 0 && returnvect.back() < 0 )  // if curr stone and the last stone , both -ve
        ){
                returnvect.push_back(curr_asteroid);
                continue;
            }
            
            // now here 2 things 1. both asteroids direction (sign) is different 
            // but while popping back the elements they may be equal or sign may chnange

            else {
                while (!returnvect.empty())
                {
                    // case 1 : vector last element -ve , curr +ve 
                    if ( returnvect.back() <0 && curr_asteroid >0 ) {
                        // add both as both are going in diff directions 
                        break;

                    }

                    // case 2 : vector last element +ve , curr -ve 
                    else if ( returnvect.back() >0 && curr_asteroid <0 ) {
                        // if the curr stone val is more , it will destroy the prev stone 
                        if ( returnvect.back() < abs (curr_asteroid) ){
                            returnvect.pop_back();
                        }
                        else if ( returnvect.back() == abs( curr_asteroid ) ) { // if both equal
                            // both gets destroyed 
                            returnvect.pop_back();
                            curr_asteroid=0;
                            break;
                        }
                        // else the curr stone will be destoyed 
                        else {
                            curr_asteroid = 0;
                            break;
                        }
                    }

                    // both values -ve / +ve  (for future ) , then no destory or etc 
                    // then add the curr element into the vector 
                    else{
                        break;
                    }
                }          
                if (curr_asteroid!=0){
                    returnvect.push_back(curr_asteroid);
                }
            }
        }

        return returnvect;
    }
};



int main (){

    
    return 0;
}