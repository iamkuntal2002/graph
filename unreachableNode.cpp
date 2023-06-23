#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
class Solution1 {
public:
    //simple logic but got tle at some test cases
    void dfs(vector<int> adj[],vector<bool> &vis,int &cmp,int node){
        vis[node] = true;
        cmp++;
        for(auto adjnode : adj[node]){
            if(!vis[adjnode]) dfs(adj,vis,cmp,adjnode);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n+1];
        for(auto ed : edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        vector<int> cmp;
        vector<bool> vis(n+1,false);
        for(int i =0;i<n;i++){
            if(!vis[i]){
                int comp = 0;
                dfs(adj,vis,comp,i);
                cmp.push_back(comp);
            }
        }
        long long ans = 0;
        if(cmp.size() == 1) return ans;
        for(int i =0;i<cmp.size()-1;i++){
            int curr = cmp[i];
            for(int j =i+1;j<cmp.size();j++){
                ans += (long)curr*cmp[j];
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    //accepted solution
    void dfs(vector<int> adj[],int node, vector<bool> &vis,int &comp){
        vis[node] = true;
        comp++;
        for(auto adjnode : adj[node]){
            if(!vis[adjnode]) dfs(adj,adjnode,vis,comp);
            }
        }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n+1];
        for(auto &ed : edges){
            int u = ed[0];
            int v = ed[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long ans = 0;
        int comp = 0;
        vector<int> temp;
        vector<bool> vis(n+1,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                comp =0;
                dfs(adj,i,vis,comp);
                temp.push_back(comp);
                }
            }
        int total = 0;
        for(int i = 0; i<temp.size();i++){
            ans += (long)temp[i]*(n-total-temp[i]);
            total+= temp[i];
            }
        return ans;
    }
};