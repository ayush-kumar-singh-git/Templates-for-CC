#include <bits/stdc++.h>
using namespace std;

// Check ith bit is set or not
bool checkBit(int n, int i) { return (n >> i) & 1; }

// Set ith bit
int setBit(int n, int i) { return n | (1LL << i); }

// Clear ith bit
int clearBit(int n, int i) { return n & ~(1LL << i); }

// Toggle ith bit
int toggleBit(int n, int i) { return n ^ (1LL << i); }

// Remove lowest set bit
int removeLowestSetBit(int n) { return n & (n - 1); }

// Extract lowest set bit
int lowestSetBit(int n) { return n & (-n); }

// Power of 2 check
bool isPowerOfTwo(int n) { return n > 0 && !(n & (n - 1)); }

// Count set bits
int countBits(int n) { return __builtin_popcountll(n); }

// Leading zeros
int leadingZeros(int n) { return __builtin_clzll(n); }

// Trailing zeros
int trailingZeros(int n) { return __builtin_ctzll(n); }

// MSB position (0-indexed)
int msbPos(int n) { return 63 - __builtin_clzll(n); }

// Iterate all submasks
void iterateSubmasks(int mask)
{
    for (int sub = mask; sub; sub = (sub - 1) & mask)
    {
    }
}

// Iterate all masks
void iterateMasks(int n)
{
    for (int mask = 0; mask < (1LL << n); mask++)
    {
    }
}

int main()
{
    return 0;
}
