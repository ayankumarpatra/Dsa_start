#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// first lets create a func that merge 2 sorted arrays

void array_merger(const vector<int>& vect1,const vector<int>& vect2,vector<int> & result){
    int index1=0,index2=0,result_index=0;

    while (index1<vect1.size() && index2<vect2.size())
    {
        if(vect1[index1]<vect2[index2]){
            result[result_index++]=vect1[index1++];
        }
        else{
            result[result_index++]=vect2[index2++];
        }
    }

    if(index1<vect1.size()){
        while (index1<vect1.size())
        {
            result[result_index++]=vect1[index1++];
        } 
    }
    else if(index2<vect2.size()){
        while (index2<vect2.size())
        {
            result[result_index++]=vect2[index2++];
        } 
    }
    
}

void merge_sort(vector<int>& v){

    int n=v.size();
        if (n==1){
            return;
        }
    int n1=(n/2),n2=n-(n/2);
    vector<int> a(n1),b(n2);

    // copy pasting vectors

    for (int i=0;i<n1;i++){
        a[i]=v[i];
    }
    for (int i=0;i<n2;i++){
        b[i]=v[i+n1];// note , must add the n1 , else it will still add 0 to 1 again in n2 
    }

    // magic the recursion

    merge_sort(a);
    merge_sort(b);


    // merge
    array_merger(a,b,v);

}

int main()
{

    int arr_a[] = {1, 2, 3, 4};
    int arr_b[] = {5, 6, 7, 8};

    // instead of static arr , better to use vectors ...

    int a_size = sizeof(arr_a) / sizeof(arr_a[0]);
    int b_size = sizeof(arr_b) / sizeof(arr_b[0]);

    // and you can easily convert them (the static arrays to vectors) like

    vector<int> a(arr_a, arr_a + a_size); // array name , arrayname+size
    vector<int> b(arr_b, arr_b + b_size);

    // creating a resultant vector here , else you can do push back easily even from the func 

    vector<int> result(a.size()+b.size());

    array_merger(a,b,result);

    for(int num :result){
        cout<<num<<" ";
    }


    // now starting with merge sort


        return 0;
}