#include<iostream>
#include<unordered_map>
#include<vector>
#include<utility>

using namespace std ;

/*
used to 
1. freq array or set 
2. store a key, val or index 


similar to set , insertion , deleting , searching all O(1)


// pairclass   must add utility in header file 

A pair is declared with the types of the two elements, which can be the same or different (e.g., pair<int, string>). Accessed via the .first and .second.

pair<int,int> p (5,67);

to get 5 p.first// no braces eg() x

or pair <int,string> mark (59,marks)




// similarly unordered map also takes 2 things <key,value> 

eg unorderedmap<string,int> and see you cant only 0insert a string or int , whole value pair will be inserted 
so make a pair , then insert val , then insert in map


*/


int main (){

    unordered_map <string,int> mp;

    pair<string,int> p;

    p.first="Ayan";
    p.second=124;
    mp.insert(p);


    p.first="Avik";
    p.second=129;
    mp.insert(p);

    // also without the pair thing you can do like 
    mp["Dj"]=155;// mapname[key]= value; automatically create a key value pair

    for (auto p:mp){// auto automatically detects type else have to write pair<type1,type2>
        cout<<"Name : "<<p.first<<" Roll No : "<<p.second<<endl;
    }
    
    
    // to delete an value pair , use mapname.erase(key)

    mp.erase("Dj");// write exact key name even if you wrie dj it will not delete anything 
    
    for (auto p:mp){// auto automatically detects type else have to write pair<type1,type2>
        cout<<"Name : "<<p.first<<" Roll No : "<<p.second<<endl;
    }


    /*
    finding 

    mapname.find(key)!=map.end()
    
    */
    
    return 0;
}