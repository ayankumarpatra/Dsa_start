#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<stack>
#include<utility>

using namespace std ;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
    
    vector<int> returnvect(n,0);// no of tasks already given;

    stack<pair<int,int>> st;

    for (int i=0;i<logs.size();i++){
        stringstream ss(logs[i]);
        string s;
        getline(ss,s,':');// segment 1 , function id 
        int fid=stoi(s);

        getline(ss,s,':');// 2nd part func start or stop
        string curr_op=s;

        getline(ss,s,':');// 3 rd part or time (index)
        int currtime=stoi(s);

        if (curr_op=="start"){
            st.push ({fid,currtime});
        }

        else{
            if (st.size()>0){

                pair <int,int> temp =st.top();
                int duration=0;// time needed for the current activity 

                if (fid==temp.first){
                    st.pop();
                    duration=currtime-temp.second+1;
                    returnvect[fid]=returnvect[fid]+duration;

                    if(st.size()>0){
                        temp=st.top();
                        // subtacting the curr duration for the next waiting task if any 
                        returnvect[temp.first]-=duration;
                    }
                }
            }
        }

    }

    return returnvect;

    }
};


int main (){

    
    return 0;
}