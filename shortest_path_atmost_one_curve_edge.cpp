#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/e7d81a082cda6bd1e959d943197aa3bc21b88bdb/1
vector<int> dijkstra(int n, int a, int b, vector<pair<int, int>> adj[])
{
    vector<int> dist(n + 1, 1e9);
    dist[a] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, a});
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        int dis = curr.first;
        int node = curr.second;
        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;
            if (dist[v] > dis + wt)
            {
                dist[v] = dis + wt;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges)
{
    // code here
    vector<pair<int, int>> adj[n + 1];
    vector<vector<int>> curve;
    for (auto &e : edges)
    {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
        curve.push_back({e[0], e[1], e[3]});
    }
    vector<int> dist1 = dijkstra(n, a, b, adj);
    vector<int> dist2 = dijkstra(n, b, a, adj);
    int ans = dist1[b];
    for (int i = 0; i < m; i++)
    {
        int u = curve[i][0];
        int v = curve[i][1];
        int cwt = curve[i][2];
        ans = min(ans, dist1[u] + cwt + dist2[v]);
        ans = min(ans, dist1[v] + cwt + dist2[u]);
    }
    if (ans >= 1e9)
        return -1;
    return ans;
}