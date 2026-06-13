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
    }
    return 0;
}

int blockSize;

struct Query {
    int l, r, idx;
};

bool cmp(const Query &a, const Query &b) {
    int block_a = a.l / blockSize;
    int block_b = b.l / blockSize;

    if (block_a != block_b) return block_a < block_b;

    if (block_a & 1) return a.r > b.r;

    return a.r < b.r;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<Query> v(q);
    for (int i = 0; i < q; i++) {
        cin >> v[i].l >> v[i].r;
        v[i].l--;
        v[i].r--;
        v[i].idx = i;
    }
    blockSize = sqrt(n);
    sort(all(v), cmp);
    int L = 0, R = -1;
    int curAns = 0;
    vector<int> ans(q, 0);

    // if required do coordinate compression
    // vector<int> vals = c;
    // sort(all(vals));
    // vals.erase(unique(all(vals)), vals.end());

    // for (int i = 0; i < n; i++)
    // {
    //     c[i] = lower_bound(all(vals), c[i]) - vals.begin();
    // }
    // vector<int> f(vals.size() + 1, 0);

    vector<int> f(n + 1, 0);
    auto add = [&](int idx) {
        f[c[idx]]++;

        if (f[c[idx]] == 1) curAns++;
    };

    auto remove = [&](int idx) {
        f[c[idx]]--;

        if (f[c[idx]] == 0) curAns--;
    };
    for (int i = 0; i < q; i++) {
        int l = v[i].l, r = v[i].r, idx = v[i].idx;
        while (L > l) {
            L--;
            add(L);
        }

        while (R < r) {
            R++;
            add(R);
        }

        while (L < l) {
            remove(L);
            L++;
        }

        while (R > r) {
            remove(R);
            R--;
        }

        ans[idx] = curAns;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}
