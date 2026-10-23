 #include<iostream>
 #include<stack>
 #include<vector>
 
 using namespace std ;
 
 
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int firstcolor=colors[0],front=0;

        for (int i=colors.size()-1;i>=0;i--){
            if (colors[i]!=firstcolor){
                front=i;
                break;
            }
        }

        int lastcolor=colors[colors.size()-1],back=0;

        for(int i=0;i<colors.size();i++){
            if (colors[i]!=lastcolor){
                back=i;
                break;
            }
        }

        return max(front,int(colors.size())-1-back);
    }
};
 



 int main (){
 
     
     return 0;
 }