#include <bits/stdc++.h>
using namespace std;
void dfs(int src, vector<int> adj[], vector<int> &vis)
{
    vis[src] = 1;
    for (auto ele : adj[src])
    {
        if (vis[ele] != 1)
        {
            dfs(ele, adj, vis);
        }
    }
};
bool circleOfWords(vector<string> &words)
{ // Write your code here.
    vector<int> adj[26];
    vector<int> tranpose[26];
    vector<int> in(26, 0);
    vector<int> out(26, 0);
    int src = -1;
    for (auto ele : words)
    {
        int u = ele.front() - 'A';
        int v = ele.back() - 'A';
        if (src == -1)
        {
            src = u;
        }
        adj[u].push_back(v); // adj[v].push_back(u)
        in[v]++;
        out[u]++;
        tranpose[v].push_back(u);
    }
    for (int i = 0; i < 26; i++)
    {
        if (in[i] != out[i])
            return false;
    }
    vector<int> vis(26, 0);
    dfs(src, adj, vis);
    for (int i = 0; i < 26; i++)
    {
        if (adj[i].size() != 0 and vis[i] == 0)
            return false;
    }
    vector<int> vis1(26, 0);
    dfs(src, tranpose, vis1);
    for (int i = 0; i < 26; i++)
    {
        if (tranpose[i].size() != 0 and vis1[i] == 0)
            return false;
    }
    return true;
}