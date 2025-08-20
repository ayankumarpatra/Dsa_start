// Given an integer n, return the number of prime numbers that are strictly less than n.

/*
#include<iostream>
#include<cmath>
using namespace std ;

bool prime_checker(int num){
    if (num==2 || num==3 ||num==5) return true;
    if (num<=1 || num%2==0 || num%3==0 ||num%5==0) return false;
    int temp=sqrt(num);
    for (int i=7;i<=temp;i++){
        if(num%i==0)
            return false;
    }
    return true;
}

int countPrimes(int range) {
    if (range <= 2) return 0;

    int count = 1;  // count prime "2"
    for (int i = 3; i < range; i += 2) {  // check only odds
        if (prime_checker(i))
            count++;
    }
    return count;
}

int main (){
int range;
cout<<"Enter the range ";
cin>>range;

cout<<countPrimes(range);
    return 0;
}



sieve of eratos thenesis


*/

#include<iostream>
#include<cmath>
#include<vector>// to use vector .. , dynamic araay 
using namespace std ;

class Solution {
public:
    void fillSieve (vector<bool>&sieve){
        int n= sieve.size()-1; 
        for (int i=2;i<=sqrt(n);i++){
            for(int j=i*2;j<=n;j+=i){
                sieve[j]=0;
            }
        }
    };
    int distinctPrimeFactors(int n) {
        if (n<=2) return 0;
        n=n-1;
        int count =0;
        vector<bool> sieve(n+1,1);//1 means prime
        fillSieve(sieve);
        sieve[0]=0;
        sieve[1]=0;
    for (int i=2;i<=n;i++){
        if (sieve[i]==1) count++;
    }
    return count;
    }
};

int main (){

    return 0;
}
/*
more better approach 

int countPrimes(int n) {
    if (n <= 2) return 0;

    vector<bool> isPrime(n, true);  // create array
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;  // mark multiples as not prime
            }
        }
    }

    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) count++;
    }
    return count;
}

*/