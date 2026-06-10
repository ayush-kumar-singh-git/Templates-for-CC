#include <bits/stdc++.h>
using namespace std;

struct SparseTable
{
    int n;
    vector<vector<int>> st;
    vector<int> lg;
    SparseTable(vector<int> &a)
    {
        n = a.size();
        int K = __lg(n) + 1;
        st.assign(n, vector<int>(K));
        lg.assign(n + 1, 0);
        // Precompute logs
        for (int i = 2; i <= n; i++)
        {
            lg[i] = lg[i / 2] + 1;
        }
        // Base layer
        for (int i = 0; i < n; i++)
        {
            st[i][0] = a[i];
        }
        // Build sparse table
        for (int j = 1; j < K; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    // Query minimum on [l, r]
    int query(int l, int r)
    {
        int j = lg[r - l + 1];
        return min(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

int main() { return 0; }
