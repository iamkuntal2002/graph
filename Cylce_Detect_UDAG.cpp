#include<bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node, vector<int> &vis, vector<int> adj[],int parent){
        vis[node] =1;
        for(int it: adj[node]){
            if(!vis[it]) {
                if(dfs(it,vis,adj,node))
                    return true;
            }
            else if(it != parent) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i =0;i< V;i++){
            if(vis[i] == 0){
                if(dfs(i,vis,adj,-1)) return true;
            }
        }
        return false;
    }
};
int main(){
    
}