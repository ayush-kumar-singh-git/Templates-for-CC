#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> v(n), ps(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        ps[i] = ps[i - 1] + v[i];
    }
    // query [l,r] = ps[r+1] - ps[l] // 0 based indexing
    int m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            pref[i][j] =
                a[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
    /* Query Sum Rectangle: (x1, y1) -> (x2, y2) (1 based)
    pref[x2][y2]
    - pref[x1 - 1][y2]
    - pref[x2][y1 - 1]
    + pref[x1 - 1][y1 - 1]
    */
    return 0;
}
