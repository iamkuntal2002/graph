#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
bool bfs(int node, vector<int> adj[], vector<bool> &vis)
{
    queue<pair<int, int>> qu; // v,parent;
    qu.push({node, -1});
    vis[node] = true;
    while (!qu.empty())
    {
        int v = qu.front().first;
        int parent = qu.front().second;
        qu.pop();
        for (int u : adj[v])
        {
            if (!vis[u])
            {
                vis[u] = true;
                qu.push({u, v});
            }
            else if (u != parent)
                return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            if (bfs(i, adj, vis))
                return true;
    }
    return false;
}
int main()
{
}