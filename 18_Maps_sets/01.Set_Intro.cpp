#include<iostream>
#include<stack>
#include<vector>
#include<unordered_set>
//set and unordered set both are different 

using namespace std ;


int main (){
    
    // initialization like vector
    
    unordered_set<int> sa;
    
    sa.insert(1);
    /*
    doesnt matter how many times you insert the 1 , it will be added 1 time only 
    and elements are added randomly , not in a ordered manner

    and no index , top , front back etc thing , you must use thing like 

    for int x: unordererd set name 

    and set only adda an element only once , even if you add multiple times still the element will exist one time only 

    how to check if an element exist in a set or not 

    if (setname.find(target)!=s.end()) // if said == its not exists{
        print exists
    }

    here s.find() searches in the set and if its not found then it returns the last element 

    
    */
   sa.insert(5);
   sa.insert(6);
   sa.insert(7);
   sa.insert(2);
   sa.insert(5);


   int target;
   cout<<"Enter target element to search: ";
   cin>>target;

   if (sa.find(target)!=sa.end()){
    cout<<"Target exists\n";
   }
   else {
    cout<<"Target Doesnt exist \n";
   }
    
    return 0;
}