#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

//Menu Driven Programs for Insertion, Deletion, Updating, Search, Display for an array

class arr{
    public:
    int maxsize,currsize;
    int *currarr;

    arr(int size){
        maxsize=size;
        currsize=0;

        currarr=new int [maxsize];
    }

    void insert(int val,int pos){
        if (pos>maxsize){
            cout<<"\ninvalid pos to add the element\n";
            return;
        }
        currarr[pos]=val;
        cout<<val<<" added in pos "<<pos<<endl;
    }
    
    void deletebyindex(int index){
        if (index>=currsize){
            cout<<"\ninvalid pos to delete the element\n";
            return;
        }

        else{
            for (int i=index;i<maxsize-1;i++){
                currarr[i]=currarr[i+1];
            }
        }
    }

    void updatebyval(int val,int toupdate){// search is also like this so i will better focus on other concepts 
        for (int i=0;i<currsize;i++){
            if (currarr[i]==val){
                swap(currarr[i],toupdate);
                return;
            }
        }
        cout<<"Value not present in arr";
    }

    void display(){
        for (int i=0;i<currsize;i++){
            cout<<currarr[i]<<" ";
        }
        cout<<endl;
    }

};


int main (){

    int choice,currlen;

    cout<<"Enter the array length : ";
    cin>>currlen;

    arr arr(currlen);

    while (1)
    {
        cout<<"Available options are : \n1.insert 2.delete \n3.display 4.Exit\nEnter your choice: ";

        cin>>choice;

        if (choice==1){
            int idx,val;
            cout<<"Enter index and value to insert";
            cin>>idx>>val;
            arr.insert(val,idx);
        }
        else if (choice==2){
            int curri;
            cout<<"Enter index to delete";
            cin>>curri;
            arr.deletebyindex(curri);
        }

        else if (choice==3){
            arr.display();
        }

        else if (choice==4){
            break;
        }
    }
     
    return 0;
}