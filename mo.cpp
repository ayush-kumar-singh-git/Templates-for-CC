#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Query {
    int l, r, idx;

    bool operator<(const Query &other) const {
        static int BLOCK_SIZE = 450;

        int block_a = l / BLOCK_SIZE;
        int block_b = other.l / BLOCK_SIZE;

        if (block_a != block_b) return block_a < block_b;

        // Optional optimization
        if (block_a & 1) return r > other.r;

        return r < other.r;
    }
};

const int MAXN = 200005;

int n, q;
int arr[MAXN];

Query queries[MAXN];
ll ans[MAXN];

// ===============================
// CHANGE ONLY THESE FUNCTIONS
// ===============================

void add_(int idx) {
    // add arr[idx] into current range
}

void delete_(int idx) {
    // remove arr[idx] from current range
}

ll get_answer() {
    // return current answer
    return 0;
}

// ===============================

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;

        // convert to 0-index if input is 1-indexed
        queries[i].l--;
        queries[i].r--;

        queries[i].idx = i;
    }

    sort(queries, queries + q);

    int cur_l = 0;
    int cur_r = -1;

    for (int i = 0; i < q; i++) {
        int L = queries[i].l;
        int R = queries[i].r;

        while (cur_r < R) {
            cur_r++;
            add_(cur_r);
        }

        while (cur_r > R) {
            delete_(cur_r);
            cur_r--;
        }

        while (cur_l < L) {
            delete_(cur_l);
            cur_l++;
        }

        while (cur_l > L) {
            cur_l--;
            add_(cur_l);
        }

        ans[queries[i].idx] = get_answer();
    }

    for (int i = 0; i < q; i++) cout << ans[i] << '\n';

    return 0;
}
