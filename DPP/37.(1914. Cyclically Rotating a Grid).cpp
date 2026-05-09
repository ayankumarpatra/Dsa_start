#include<iostream>
#include<queue>
#include<vector>

using namespace std ;

// approach 1 , tried in place end up with a complex idea and that didnt succeed 


// approach 2 trying to remove outer layer , do the rotation , reput it back 


class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        // first detting the boundaries
        int Rowmin=0,Colmin=0,Rowmax=grid.size(),Colmax=grid[0].size();
        int max_travel=min(Rowmax+1,Colmax+1)/2;

        for (int j=0;j<max_travel;j++){

            queue<int> q;
            // now putting elements in the q

            for (int i=Colmin;i<Colmax;i++) q.push(grid[Rowmin][i]);
            for (int i=Rowmin;i<Rowmax;i++) q.push(grid[i][Colmax]);
            for (int i=Colmax;i>Colmin;i--) q.push(grid[Rowmax][i]);
            for (int i=Rowmax;i>Rowmin;i--) q.push(grid[i][Colmin]);
            
            // not modifying rowmin , colmin anything , as we need to refill it 
            int rotate=k%q.size();
            
            while (rotate-->0)
            {
                int temp=q.front();
                q.pop();
                q.push(temp);
            }
            
            // similar loop like reading 
            for (int i=Colmin;i<Colmax;i++) {grid[Rowmin][i]=q.front(); q.pop(); }
            for (int i=Rowmin;i<Rowmax;i++) {grid[i][Colmax]=q.front(); q.pop(); }
            for (int i=Colmax;i>Colmin;i--) {grid[Rowmax][i]=q.front(); q.pop(); }
            for (int i=Rowmax;i>Rowmin;i--) {grid[i][Colmin]=q.front(); q.pop(); }

            Rowmin++,Colmin++,Rowmax--,Colmax--;
        }
        return grid;
    }
};



int main (){

    
    return 0;
}