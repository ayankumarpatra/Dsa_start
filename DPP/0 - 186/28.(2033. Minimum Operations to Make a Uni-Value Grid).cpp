#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // making the grid flat ;
        // simultaneously checking that if currnum= 0 th num %x==0 or not , else we cant flat it by add or sub

        vector<int> vect;
        int num1=grid[0][0];

        for(int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                vect.push_back(grid[i][j]);
                if (abs((grid[i][j]-num1)%x)!=0){// check point 2 on top
                    return -1;
                }
            }
        }

        sort(vect.begin(),vect.end());

        int mid=vect[(vect.size()-1)/2];// getting the perfect mid value 

        int minop=0;

        for (int i=0;i<vect.size();i++){
            int temp=(abs(vect[i]-mid)/x);// no of operations needed to be equal with mid 
            // eg if diff is 6 and x is 2 then  operation need is 6/2 =3 , doesnt define if its add or sub 
            minop+=temp;
        }

        return minop;
    }
};


int main (){

    
    return 0;
}