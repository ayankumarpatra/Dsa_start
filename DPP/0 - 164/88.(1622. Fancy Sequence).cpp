#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Fancy {
public:

    using ll = long long;
    const ll mod = 1000000007;

    // stores normalized values
    vector<ll> values;

    // global transformation
    ll multiply_factor = 1;
    ll add_factor = 0;

    // fast modular exponentiation
    ll mod_pow(ll base, ll power){

        ll result = 1;

        while(power){

            if(power & 1)
                result = (result * base) % mod;

            base = (base * base) % mod;
            power >>= 1;
        }

        return result;
    }

    Fancy() {}

    void append(int val) {

        // compute modular inverse of multiply_factor
        ll inverse_mul = mod_pow(multiply_factor, mod - 2);

        // normalize the value before storing
        ll normalized_value = ((val - add_factor) % mod + mod) % mod;

        normalized_value = (normalized_value * inverse_mul) % mod;

        values.push_back(normalized_value);
    }

    void addAll(int inc) {

        // update global addition
        add_factor = (add_factor + inc) % mod;
    }

    void multAll(int m) {

        // update both multiplication and addition
        multiply_factor = (multiply_factor * m) % mod;
        add_factor = (add_factor * m) % mod;
    }

    int getIndex(int idx) {

        // index does not exist
        if(idx >= values.size())
            return -1;

        // apply global transformation
        ll result = (values[idx] * multiply_factor % mod + add_factor) % mod;

        return result;
    }
};


int main (){

    
    return 0;
}