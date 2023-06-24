//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //prim's algo
        vector<int> key(V,INT_MAX);
        vector<bool> mst(V,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> qu;//weight,node
        qu.push({0,0});
        key[0] =0;
        while(!qu.empty()){
            auto pr = qu.top();
            qu.pop();
            int node = pr.second;
            int w = pr.first;
            mst[node] = true;
            for(auto v : adj[node]){
                int vertex = v[0];
                int weight = v[1];
                if(!mst[vertex] && weight<key[vertex]){
                    key[vertex] = weight;
                    qu.push({key[vertex],vertex});
                }
            }
        }
        //upto that we store the all min path from 0 to all the vertex
        int total_cost =0;
        for(auto w : key){
            total_cost += w;
        }
        return total_cost;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends