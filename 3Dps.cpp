#include <bits/stdc++.h>
using namespace std;

#define int long long
#define Int __int128_t
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int MOD = 1e9 + 7;

void solve();

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
        cout << "\n";
    }
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<vector<int>>> v(n, vector<vector<int>>(n, vector<int>(n)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> v[i][j][k];
            }
        }
    }
    vector<vector<vector<int>>> ps(
        n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ps[i + 1][j + 1][k + 1] =
                    v[i][j][k] + ps[i][j + 1][k + 1] + ps[i + 1][j + 1][k] +
                    ps[i + 1][j][k + 1] - ps[i][j][k + 1] - ps[i][j + 1][k] -
                    ps[i + 1][j][k] + ps[i][j][k];
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        // 1 based formula here
        int ans = ps[x2][y2][z2] - ps[x1 - 1][y2][z2] - ps[x2][y1 - 1][z2] -
                  ps[x2][y2][z1 - 1] + ps[x1 - 1][y1 - 1][z2] +
                  ps[x1 - 1][y2][z1 - 1] + ps[x2][y1 - 1][z1 - 1] -
                  ps[x1 - 1][y1 - 1][z1 - 1];
        cout << ans << "\n";
    }
}
