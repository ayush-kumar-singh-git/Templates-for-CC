#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define maxN 1 << 20

ll tree[2 * maxN];

ll query(int idx, int node_lo, int node_hi, int query_lo, int query_hi) {
    if (query_lo <= node_lo && node_hi <= query_hi) {
        return tree[idx];
    }

    if (node_hi < query_lo || node_lo > query_hi) {
        return 0;
    }

    int mid = node_lo + (node_hi - node_lo) / 2;

    ll ans = query(2 * idx, node_lo, mid, query_lo, query_hi) +
             query(2 * idx + 1, mid + 1, node_hi, query_lo, query_hi);
    return ans;
}

void update(int idx, int node_lo, int node_hi, int query_lo, int query_hi,
            int val) {
    if (query_lo <= node_lo && node_hi <= query_hi) {
        tree[idx] = val;
        return;
    }

    if (node_hi < query_lo || node_lo > query_hi) {
        return;
    }

    int mid = node_lo + (node_hi - node_lo) / 2;

    update(2 * idx, node_lo, mid, query_lo, query_hi, val);
    update(2 * idx + 1, mid + 1, node_hi, query_lo, query_hi, val);

    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    return;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // making n a power of 2
    int sz = 1;
    while (sz < n) sz <<= 1;
    n = sz;

    // building the tree
    for (int i = 0; i < n; i++) {
        tree[n + i] = v[i];
    }

    for (int i = n - 1; i >= 1; i--) {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 2) {
            l--;
            r--;
            cout << query(1, 0, n - 1, l, r) << "\n";
        } else {
            l--;
            v[l] = r;
            update(1, 0, n - 1, l, l, r);
        }
    }
    return 0;
}
