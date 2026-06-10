#include <bits/stdc++.h>
using namespace std;

const int INF = 1e18;
#define MAXN 100005

vector<pair<int, int>> adj[MAXN];

vector<int> dist(MAXN, INF);

void dijkstra(int src, int n)
{

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto [d, node] = pq.top();
        pq.pop();
        if (d > dist[node])
            continue;
        for (auto [next, wt] : adj[node])
        {
            if (dist[node] + wt < dist[next])
            {
                dist[next] = dist[node] + wt;
                pq.push({dist[next], next});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dijkstra(1, n);
    if (dist[n] == INF)
        cout << -1;
    else
        cout << dist[n];
    return 0;
}