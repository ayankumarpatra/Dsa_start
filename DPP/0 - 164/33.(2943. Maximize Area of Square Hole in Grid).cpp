#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;
/*

class Solution {
    public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

    int maxarea=-1e9;
    int tempcurrarea=0,cornercounter=0;
    
    int max_iteration=min(hBars.size(),vBars.size());// only till the bars can be removed 
    // can form a square rest cant 
    
    //as per the testcases vbar and hbar is sorted else will use built in sort func sort(v1.begin(),v1.end())
    
    for (int i=0;i<max_iteration;i++){
                //as both array is sorted so to be free there the removable bar must be in index 
                
               // i mean i am starting from 0,0 now if 1 is not free we cant extend the square more 
                
               
               if (&hBars[i]==&vBars[i]){
                   tempcurrarea+=4+cornercounter;
                   /*
                    as per my self observation each time i move diagonally which is pbvious need to make a square 
                    the total area increases like the 1st 0,0 so we get a aquare of area 4 
                    next 1,1, area = 5, next 2,2 area = 7 , so 4 +0 -> 4+1 -> 4+3 ->...
                   //
                   
                    if (tempcurrarea==4){
                        cornercounter+=1;
                    }

                    else{
                        cornercounter+=2;
                    } 
                }
                
                else {
                    maxarea=max(maxarea,tempcurrarea);
                    tempcurrarea=0;
                    cornercounter=0;
                }
            }
            return maxarea;
    }
};

failed attempt 
*/

class Solution {
public:
    int getmaxlen(vector<int> & side1,vector<int> & side2){
            if (side1.size()==1 || side2.size()==1){
                return 1;
            }
        sort(side1.begin(),side1.end());
        sort(side2.begin(),side2.end());

        int side1len=side1.size(),side2len=side2.size();
        int maxit=max(side1.size(),side2.size());
        int tempside1=1,tempside2=1;
        int max1=0,max2=0;

        for (int i=1;i<maxit;i++){// starting from index 1 to compare with back index
            if (i<side1len){
                if (side1[i]==side1[i-1]+1){// consecutive bars 
                    tempside1+=1;
                }
                else{
                    max1=max(max1,tempside1);
                    tempside1=1;
                }
            }

            // similarly for side 2
            if (i<side2len){
                if (side2[i]==side2[i-1]+1){// consecutive bars 
                    tempside2+=1;
                }
                else{
                    max2=max(max2,tempside2);
                    tempside2=1;
                }
            }

             max1=max(max1,tempside1);
             max2=max(max2,tempside2);
        }
        return min(max1,max2);
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        int maxpossside=getmaxlen(hBars,vBars)+1;

        return maxpossside*maxpossside;
    }
};


int main (){

    
    return 0;
}