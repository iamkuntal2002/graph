#include <bits/stdc++.h>
using namespace std;
bool bfs(vector<vector<int>> &adj, int node, vector<bool> &vis)
{
    queue<int> qu;
    qu.push(node);
    vis[node] = true;
    int nodes = 0;
    int edges = adj[node].size();
    bool flag = true;
    while (!qu.empty())
    {
        int currnode = qu.front();
        qu.pop();
        nodes++;
        if (adj[currnode].size() != edges)
            flag = false;
        for (auto adjnode : adj[currnode])
        {
            if (!vis[adjnode])
            {
                vis[adjnode] = true;
                qu.push(adjnode);
            }
        }
    }
    return flag && edges + 1 == nodes;
}
int findNumberOfGoodComponent(int V, vector<vector<int>> &adj)
{
    // code here
    vector<bool> vis(V + 1, false);
    int count = 0;
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            if (bfs(adj, i, vis))
                count++;
        }
    }
    return count;
}
int main(){
    
}