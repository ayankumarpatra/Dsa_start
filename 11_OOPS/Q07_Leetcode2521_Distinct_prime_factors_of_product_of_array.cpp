/*

// fixed the wholw code after 1 day of hard work , finally i did it 

Input: nums = [2,4,3,7,10,6]
Output: 4
Explanation:
The product of all the elements in nums is: 2 * 4 * 3 * 7 * 10 * 6 = 10080 = 25 * 32 * 5 * 7.
There are 4 distinct prime factors so we return 4.

Example 2:

Input: nums = [2,4,8,16]
Output: 1
Explanation:
The product of all the elements in nums is: 2 * 4 * 8 * 16 = 1024 = 210.
There is 1 distinct prime factor so we return 1.

*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std ;

bool isprime (int n){
    if (n==2) return 1;
    if (n<2 || n%2==0) return 0;
    for (int i=3;i<=sqrt(n);i+=2){
        if (n%i==0)
            return 0;
    }
    return 1;
}

int distinctPrimeFactors(vector<int>&nums) {
        int sz=nums.size(),max=0,uniqueval=0;
        for (int i=0;i<sz;i++){
            if (nums[i]>max)
                max=nums[i];
        }
        if (sz==1){
        if (isprime(nums[0]))
            return 1;
        }
        vector<int> primefactors;
        if (max>1 && sz>0){
        primefactors.push_back(2);
        uniqueval++;
        for(int i=3;i<=max;i++){
            if(isprime (i) ){
                primefactors.push_back(i);
                uniqueval++;
            }
        }
    }
    int totalfactors=0;
        for(int i=0;i<uniqueval;i++){
            for(int j=0;j<sz;j++){
                if(nums[j]%primefactors[i]==0){
                    totalfactors ++;
                    break;
                }
            }
        }
    return totalfactors;
    }
int main (){
int sz;
cout<<"Enter the expected no of elements";
cin>>sz;
vector<int> numbers (sz);
cout<<"Enter "<<sz<<"elements"<<endl;
for (int i=0;i<sz;i++){
    cin>>numbers[i];
}

cout<<"No of prime distinct Prime Factors is "<<distinctPrimeFactors(numbers);

    return 0;
}