#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int addM(int a, int b)
{
    a %= MOD;
    b %= MOD;
    return (a + b) % MOD;
}

int subM(int a, int b)
{
    a %= MOD;
    b %= MOD;
    return (a - b + MOD) % MOD;
}

int mulM(int a, int b)
{
    a %= MOD;
    b %= MOD;
    return (a * b) % MOD;
}

int binexp(int a, int b)
{
    a %= MOD;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = mulM(res, a);
        a = mulM(a, a);
        b >>= 1;
    }
    return res;
}

int invM(int a) { return binexp(a, MOD - 2); }

int divM(int a, int b) { return mulM(a, invM(b)); }

int main() { return 0; }
