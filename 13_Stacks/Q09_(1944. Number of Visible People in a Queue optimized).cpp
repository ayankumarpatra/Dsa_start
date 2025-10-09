#include<iostream>
#include<vector>
#include<stack>
using namespace std ;

vector<int> canSeePersonsCount(vector<int>& heights) {
    //optimised approach 
    int Vector_Size=heights.size(),i,count;
    stack <int> st;
    vector <int> Persons_Visible(Vector_Size,0);

    for(i=Vector_Size-1;i>=0;i--){
        count=0;
        while (st.size()>0){
        if( st.top()>=heights[i])
        {
         count++;
        break;
        }

        else {
            count++;
            st.pop();
        }
    }
        Persons_Visible[i]=count;
        st.push(heights[i]);
        
    }

    return Persons_Visible;
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