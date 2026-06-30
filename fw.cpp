#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF = LLONG_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> d(n + 1, vector<ll>(n + 1, INF));

    for (int i = 0; i <= n; i++) d[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min((ll)w, d[u][v]);
        d[v][u] = d[u][v];
    }

    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (d[u][k] != INF && d[k][v] != INF)
                    d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        if (d[u][v] == INF)
            cout << "-1\n";
        else
            cout << d[u][v] << "\n";
    }
    return 0;
}
