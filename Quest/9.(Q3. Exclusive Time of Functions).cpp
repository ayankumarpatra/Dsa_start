#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std ;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
    // ss segment parts vector
    int len=logs.size()/2;// becuase each process will have 2 operations start and stop so total task is size/2
    vector<int> parts(len,0);
    bool start,end;

    for (int i=0;i<logs.size();i++){
        stringstream ss(logs[i]);
        string segment;
        int index=0,Prev_End=0,currindex=0;

        while (getline(ss,segment,':'))
        {

            if (segment=="start"){
                start=true;
            }

            else if (segment!="start" && segment!="end"){
                if (start){/*
                    "1:start:2" like for this 1 , at index 0 is the process 
                    then start end handelled manually , 
                    then start or end point
                    */
                    index=stoi(segment);
                    start=false;
                }

                if (end){
                    end=false;
                    parts[index]=parts[index]+currindex-Prev_End;
                }
            }
            else if (segment=="end"){
                end= true;
                }

            }
        }
        
        return parts;
    }
};


int main (){

    
    return 0;
}