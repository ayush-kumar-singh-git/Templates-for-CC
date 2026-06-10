#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent;
    // Size of component
    vector<int> sz;
    DSU(int n)
    {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        // Initially every node
        // is its own parent
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    // Find representative
    int find(int x)
    {
        // Root node
        if (parent[x] == x)
            return x;
        // Path compression
        return parent[x] = find(parent[x]);
    }
    // Merge two components
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        // Already connected
        if (a == b)
            return false;
        // Union by size
        if (sz[a] < sz[b])
            swap(a, b);
        // Attach smaller tree
        // under larger tree
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
    // Check same component
    bool same(int a, int b) { return find(a) == find(b); }
    // Size of component
    int size(int x) { return sz[find(x)]; }
};
// cycle detection in a graph
// bool cycle = false;
// for (auto [u, v] : edges)
// {
//     if (dsu.same(u, v))
//     {
//         cycle = true;
//     }
//     else
//     {
//         dsu.unite(u, v);
//     }
// }

// connected components
// set<int> comps;
// for (int i = 1; i <= n; i++)
// {
//     comps.insert(dsu.find(i));
// }
// cout << comps.size();

int main()
{
    return 0;
}
