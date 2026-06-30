#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 2e5 + 7;
int LOG;
int logbase2[MAXN];

int rangeGCD(vector<vector<int>> &Table, int l, int r) {
    int len = r - l + 1;
    int k = logbase2[len];
    return gcd(Table[l][k], Table[r - (1 << k) + 1][k]);
}

bool ok(int n, vector<vector<int>> &table, int k, ll S) {
    ll score = 0;
    for (int i = 0; i < n; i++) {
        int j = i + k - 1;
        if (j >= n) break;
        score += rangeGCD(table, i, j);
    }
    return score >= S;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll S;
    cin >> n >> S;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    for (int i = 2; i <= n; i++) logbase2[i] = logbase2[i / 2] + 1;

    LOG = logbase2[n] + 1;

    vector<vector<int>> Table(n, vector<int>(LOG, 0));

    for (int i = 0; i < n; i++) {
        Table[i][0] = a[i];
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            Table[i][j] =
                gcd(Table[i][j - 1], Table[i + (1 << (j - 1))][j - 1]);
        }
    }

    int lo = 1, hi = n;
    int ans = 0;
    while (lo <= hi) {
        int k = lo + (hi - lo) / 2;
        if (ok(n, Table, k, S)) {
            ans = k;
            lo = k + 1;
        } else {
            hi = k - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
