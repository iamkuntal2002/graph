#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    // Code here
    vector<pair<int, int>> adj[n + 1];
    for (auto v : edges)
    {
        adj[v[0]].push_back({v[1], v[2]});
        adj[v[1]].push_back({v[0], v[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;
    vector<int> res(n + 1, INT_MAX), parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    qu.push({0, 1});
    res[1] = 0;
    while (!qu.empty())
    {
        int node = qu.top().second;
        int dist = qu.top().first;
        qu.pop();
        for (auto pr : adj[node])
        {
            int adjnode = pr.first;
            int adjw = pr.second;
            if (res[adjnode] > adjw + dist)
            {
                res[adjnode] = adjw + dist;
                qu.push({res[adjnode], adjnode});
                parent[adjnode] = node;
            }
        }
    }
    if (res[n] == INT_MAX)
        return {-1};
    vector<int> path;
    int node = n;
    while (parent[node] != node)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    return path;
}
int main()
{
}