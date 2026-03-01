#include<iostream>
#include<vector>

using namespace std ;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // first initializing boundary arrrays and using size n+1 , so that easily we can go to n
        // both row and col max pos start by 0 and min with n+1

        vector<int> RowMin (n+1,n+1);
        vector<int> RowMax (n+1,0);


        vector<int> Colmin (n+1,n+1);
        vector<int> ColMax (n+1,0);

        // building boundaries by pass

        for (const auto& pos :buildings){
            int x= pos[0];
            int y=pos[1];

            // updating horizontal boundaries 
            RowMin[y]=min(RowMin[y],x);
            RowMax[y]=max(RowMax[y],x);

            // updating vertical boundaries
            Colmin[x]=min(Colmin[x],y);
            ColMax[x]=max(ColMax[x],y);

        }

        int Count=0;

        // checking coverage
        
        for (const auto& pos :buildings){
            int x= pos[0];
            int y=pos[1];

            // checking horizontal coverage

            bool RowPresent=(x>RowMin[y] && x<RowMax[y]);

            // checking vertical coverage
            bool ColPresent=(y>Colmin[x] && y<ColMax[x]);


            if (RowPresent && ColPresent){
                Count++;
            }
        }

        return Count;
    }
};


int main (){

    
    return 0;
}