#include<iostream>
#include<vector>
#include<stack>
using namespace std ;

vector<int> canSeePersonsCount(vector<int>& heights) {
    //bruteforce approach 
    int Vector_Size=heights.size(),i,j,count,Prev_Height;
    vector <int> Persons(Vector_Size,0);
    for(i=0;i<Vector_Size-1;i++){
        count=0;
        Prev_Height=0;
        for(j=i+1;j<Vector_Size;j++){
            if (heights[j]>=heights[i]){
                count++;
                break;
            }
            else if(heights[j]>Prev_Height){
                count++;
                Prev_Height=heights[j];
            }
        }
        Persons[i]=count;
    }
    return Persons;
}
        


int main (){

    int Peoples;
    cout<<"Enter Approx No of peoples : ";
    cin>>Peoples;
    vector <int> Peoples_Height(Peoples);
    
    for(int i=0;i<Peoples;i++){
        cout<<"Enter the height of person "<<i+1<<" : ";
        cin>>Peoples_Height[i]; 
    }

    return 0;
}