#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

int main()
{
    vector<int> a = {1000000000, 5, -20, 5, 700};
    vector<int> comp = a;
    // Sort
    sort(all(comp));
    // Remove duplicates
    comp.erase(unique(all(comp)), comp.end());
    // Compress
    for (int &x : a)
    {
        x = lower_bound(all(comp), x) - comp.begin();
    }
    return 0;
}
