#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class ProductOfNumbers {
public:
    vector <int> nums;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int mul = 1;
        for (int i=nums.size()-1 ; i>=0 && k>0 ; i--){
            mul*= nums[i];
            k--;
            if (mul==0) {
                return 0;
            }
        }
        return mul;
    }
};


int main (){

    
    return 0;
}