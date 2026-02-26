#include<iostream>
#include<climits>
#include<vector>

using namespace std ;

class queue{
    public:
    int front,back,len,currsize;
    int * arr;

    queue(int size){
        if (size<=0){
            cout<<"Invalid Size";
            return;
        }
        front=back=currsize=0;
        len=size;
        arr= new int[len];
    }

    // push back , pop front 

    void push (int val){
        if (back>=len){
            cout<<"Queue already full ";
            return;
        }
        else {
            arr[back++]=val;
            currsize++;
        }
    }

    void pop(){
        if(currsize<=0){
            cout<<"Empty Queue\n";
        }
        else {
            front++;
            currsize--;
            
        }
    }

    void display(){
        for (int i=front;i<back;i++){
            cout<<arr[i]<<", ";
        }
        cout<<endl;
    }

};


int main (){

    int temp,choice;

    queue mainq(5);

    while (choice!=0)
    {
        cout<<"\n Here Are the available options : \n0.Exit 1.push \n2.pop 3.sisplay \nEnter your choice: ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter variable to push : ";
            cin>>temp;
            mainq.push(temp);
            break;
        case 2:
            mainq.pop();
            break;
        case 3:
            mainq.display();
            break;
        case 0:
            break;;
        default:
            break;
        }


    }   
    return 0;
}