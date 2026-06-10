#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define INF 1'000'000'000

int main()
{
    vector<pair<int, int>> intervals;

    // Sort by ending time
    sort(all(intervals), [](auto a, auto b)
         {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second; });

    int count = 0;

    // Last chosen ending time
    int lastEnd = -INF;
    for (auto [l, r] : intervals)
    {
        // Non-overlapping
        if (l >= lastEnd)
        {
            count++;
            lastEnd = r;
        }
    }

    return 0;
}
