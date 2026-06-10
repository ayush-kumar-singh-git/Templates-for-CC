#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
int fact[MAXN];
int invFact[MAXN];

int invM(int n)
{
    // add fun
    return 1;
}

void precomputeFactorials()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    invFact[MAXN - 1] = invM(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; i--)
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

int factorial(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans = (ans * i) % MOD;
    }
    return ans;
}

int nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

int nPr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return (fact[n] * invFact[n - r]) % MOD;
}
int main()
{

    return 0;
}
