#include<iostream>
#include<queue>
#include<vector>
using namespace std ;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        queue<int> q;
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }

        int rotated=0,i=0;
        
        while (q.size()!=0)
        {
            if(q.front()==sandwiches[i]){
                rotated=0;
                q.pop();
                i++;
            }

            else{
                q.push(q.front());
                q.pop();
                rotated++;
            }

            if(rotated==q.size()){
                return q.size();
            }

        }

        return q.size();
        
    }
};


int main (){

    
    return 0;
}