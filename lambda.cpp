#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

int main()
{
    vector<pair<int, int>> v;

    // Ascending second
    sort(all(v), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });

    // Descending second
    sort(all(v), [](pair<int, int> a, pair<int, int> b)
         { return a.second > b.second; });

    // Custom multi condition
    sort(all(v), [](pair<int, int> a, pair<int, int> b)
         {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first; });

    return 0;
}
