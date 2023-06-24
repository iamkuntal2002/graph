#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    // code here
    vector<int> adj[N + 1];
    for (auto ed : edges)
    {
        adj[ed[0]].push_back(ed[1]);
        adj[ed[1]].push_back(ed[0]);
    }
    queue<int> qu;
    qu.push(src); // node,dist
    vector<int> res(N, INT_MAX);
    res[src] = 0;
    while (!qu.empty())
    {
        int node = qu.front();
        qu.pop();
        for (auto v : adj[node])
        {
            if (res[node] + 1 < res[v])
            {
                res[v] = res[node] + 1;
                qu.push(v);
            }
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] == INT_MAX)
            res[i] = -1;
    }
    return res;
}

int main()
{
}
