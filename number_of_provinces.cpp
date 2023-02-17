#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], vector<bool> &vis, int u)
{
    vis[u] = true;
    for (int v : adj[u])
    {
        if (!vis[v])
            dfs(adj, vis, v);
    }
}
int numProvinces(vector<vector<int>> adj, int V) // note that, here adj is adj matrix
{
    // code here
    int count = 0;
    vector<bool> vis(V, false);
    vector<int> adj_list[V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == 1)
            {
                adj_list[i].push_back(j);
                adj_list[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            count++;
            dfs(adj_list, vis, i);
        }
    }
    return count;
}
int main(){
    
}