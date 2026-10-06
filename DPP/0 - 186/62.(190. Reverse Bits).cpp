#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


class Solution {
public:
    [[nodiscard]]
    auto reverseBits(int const value) const -> int;
};

auto Solution::reverseBits(int const value) const -> int {
    static constexpr size_t bit_count{32};

    // convert the integer to a 32-bit bitset for easy bit access
    auto bits = bitset<bit_count>(static_cast<unsigned>(value));

    // swap bits symmetrically from the outside toward the center
    for (size_t i = 0; i < bit_count / 2; ++i) {
        auto const temp = static_cast<bool>(bits[i]);
        bits[i] = bits[bit_count - i - 1];
        bits[bit_count - i - 1] = temp;
    }

    // convert the reversed bitset back to an integer
    auto const reversed = bits.to_ulong();
    return static_cast<int>(reversed);
}

int main (){

    
    return 0;
}