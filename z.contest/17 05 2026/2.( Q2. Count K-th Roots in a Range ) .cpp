#include<iostream>
#include<cmath>
#include<vector>

using namespace std ;

class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int count=0;

        int i=0;

        while (1)
        {
            int temp=round(pow(i,k));
            i++;

            if (temp>r){
                break;
            }
            else if (temp>=l){
                count++;
            }
        }

        return count;
        
    }
};


class Solution {
public:
    int kthRoot(int n, int k) {
        if (n < 0) return -1;
        int low = 0, high = (int)pow(n, 1.0/k) + 2;
        
        while (low <= high) {
            int mid = (low + high) / 2;
                        int val = 1;
            bool overflow = false;
            for (int i = 0; i < k; i++) {
                val *= mid;
                if (val > n) { overflow = true; break; }
            }
            
            if (!overflow && val == n) return mid;
            else if (!overflow && val < n) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }

    int countKthRoots(int l, int r, int k) {
        return kthRoot(r, k) - kthRoot(l - 1, k);
    }
};


int main (){

    
    return 0;
}
