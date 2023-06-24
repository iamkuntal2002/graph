#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/number-of-provinces/1
class Solution {
  public:
  void dfs(vector<int> adj[],int i, vector<bool> &vis){
      vis[i] = true;
      for(auto v : adj[i]){
          if(!vis[v])
            dfs(adj,v,vis);
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<bool> vis(V+1,false);
        vector<int> adj_list[V];
        for(int i =0;i<V;i++){
            for(int j =0;j<V;j++){
                if(adj[i][j] ==1){
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }
        
        int ans =0;
        for(int i =0;i<V;i++){
            if(!vis[i]){
                ans++;
                dfs(adj_list,i,vis);
            }
        }
        return ans;
    }
};
int main() {

}