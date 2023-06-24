#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

void getindegree(vector<pair<int, int>> adj[], vector<int> &in, int v)
{
    for (int i = 0; i < v; i++)
    {
        for (auto pr : adj[i])
        {
            in[pr.first]++;
        }
    }
}
vector<int> toposort(vector<pair<int, int>> adj[], int V)
{
    // code here
    vector<int> indegree(V + 1, 0);
    getindegree(adj, indegree, V);
    queue<int> qu;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            qu.push(i); // get the nodes which have 0 indegree
    }
    vector<int> res;
    while (!qu.empty())
    {
        int node = qu.front();
        qu.pop();
        res.push_back(node);
        for (auto v : adj[node])
        {
            indegree[v.first]--;
            if (indegree[v.first] == 0)
                qu.push(v.first);
        }
    }
    return res;
}
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    // code here
    vector<int> res(N, INT_MAX);
    vector<pair<int, int>> adj[N];
    for (auto ed : edges)
    {
        int u = ed[0];
        int v = ed[1];
        int d = ed[2];
        adj[u].push_back({v, d});
    }
    // vector<int> topo = toposort(adj,N);
    queue<int> q;
    q.push(0);
    res[0] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            int u = it.first;
            int v = it.second;
            if (res[node] + v < res[u])
                res[u] = res[node] + v;
            q.push(u);
        }
    }
    // res[0] = 0;
    // reverse(topo.begin(),topo.end());
    // while(!topo.empty()){
    //     int node = topo[topo.size()-1];
    //     topo.pop_back();
    //     for(auto pr : adj[node]){
    //         int v = pr.first;
    //         int wt = pr.second;
    //         if(res[node]+wt < res[v]) res[v] = wt+res[node];
    //     }
    // }
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] == INT_MAX)
            res[i] = -1;
    }
    return res;
}
int main(){
    
}