#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:

void visitedbfs(vector<vector<int>>& rooms , vector<bool> &getkeys){

    getkeys[0]=true;// room 0 unlocked by default
    
    queue < vector<int> > q;

    q.push(rooms[0]);
    

    while (q.size()>0)
    {
        vector<int> curr_keys= q.front();
        q.pop();

        for (int i=0;i<curr_keys.size();i++){
            if (!getkeys[curr_keys[i]]){
                getkeys[curr_keys[i]]=true;

                if (curr_keys[i]<i){ // if any prev room havent been visited , visit it 
                    q.push(rooms[curr_keys[i]]);
                }
            }
        }
    }  

}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    
    vector<bool> getkeys (rooms.size(),false);
    visitedbfs(rooms ,getkeys);

    for (int i=0;i<rooms.size();i++){
        if (getkeys[i]==false){
            return false;
        }
    }

    return true;
}
};


int main (){


    
    return 0;
}