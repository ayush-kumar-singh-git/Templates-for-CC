#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

vector<bool> isPrime(MAXN, true);
vector<int> primes;
vector<int> spf(MAXN);

void sieve(int n)
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

void spfSieve(int n)
{
    for (int i = 0; i <= n; i++)
        spf[i] = i;
    for (int i = 2; i * i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

vector<int> factorize(int x)
{
    vector<int> factors;
    while (x > 1)
    {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}

int main() { return 0; }
