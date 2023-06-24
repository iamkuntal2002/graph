#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// using priority_queue
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<int> res(V, INT_MAX);
    res[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;
    qu.push({0, S}); // wt,node
    while (!qu.empty())
    {
        int node = qu.top().second;
        int wt = qu.top().first;
        qu.pop();
        for (auto it : adj[node])
        {
            int adjWt = it[1];
            int adjNode = it[0];
            if (res[adjNode] > wt + adjWt)
            {
                res[adjNode] = wt + adjWt;
                qu.push({res[adjNode], adjNode});
            }
        }
    }
    return res;
}

// using set
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<int> res(V, INT_MAX);
    res[S] = 0;
    set<pair<int, int>> st;
    st.insert({0, S});
    while (!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int wt = it.first;
        st.erase(it);
        for (auto itt : adj[node])
        {
            int adjWt = itt[1];
            int adjNode = itt[0];
            if (res[adjNode] > wt + adjWt)
            {
                if (res[adjNode] != INT_MAX)
                    st.erase({res[adjNode], adjNode});
                res[adjNode] = wt + adjWt;
                st.insert({res[adjNode], adjNode});
            }
        }
    }
    return res;
}

int main()
{
}