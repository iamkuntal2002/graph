#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/path-with-maximum-probability/
class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<pair<int, double>> adj[n + 1]; // node -> adjnode, prob
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<double> dist(n, 0);
        priority_queue<pair<double, int>> qu; // prob,node
        qu.push({1, start});
        while (!qu.empty())
        {
            auto top = qu.top();
            qu.pop();
            double prob = top.first;
            int node = top.second;
            if (node == end)
                return prob;
            for (auto pr : adj[node])
            {
                int adjnode = pr.first;
                double adjprob = pr.second;
                if (prob * adjprob > dist[adjnode])
                {
                    dist[adjnode] = prob * adjprob;
                    qu.push({dist[adjnode], adjnode});
                }
            }
        }
        return 0;
    }
};