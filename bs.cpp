#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

// Array must be sorted

// Count elements < x
int countLessThan(vector<int> &v, int x)
{
    return lower_bound(all(v), x) - v.begin();
}

// Count elements <= x
int countLessEqual(vector<int> &v, int x)
{
    return upper_bound(all(v), x) - v.begin();
}

// Count elements > x
int countGreaterThan(vector<int> &v, int x)
{
    return v.end() - upper_bound(all(v), x);
}

// Count elements >= x
int countGreaterEqual(vector<int> &v, int x)
{
    return v.end() - lower_bound(all(v), x);
}

// Count elements in [l, r]
int countInRangeInclusive(vector<int> &v, int l, int r)
{
    return upper_bound(all(v), r) - lower_bound(all(v), l);
}

// Count elements in (l, r)
int countInRangeExclusive(vector<int> &v, int l, int r)
{
    return lower_bound(all(v), r) - upper_bound(all(v), l);
}

int main()
{
    return 0;
}
