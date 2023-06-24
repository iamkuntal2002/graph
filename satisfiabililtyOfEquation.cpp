#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/satisfiability-of-equality-equations/
class Solution {
public:
    void dfs(vector<int>adj[],int src,int dis,bool &flag,vector<int> vis){
         if(src==dis){
             flag=true;
             return;
         }
         vis[src]=true;
       for(auto x:adj[src]){
           if(!vis[x]){
             dfs(adj,x,dis,flag,vis);
           }
       }
    }
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        vector<int>adj[26];
        for(int i=0;i<n;i++){
            if(equations[i][1]=='='){
              adj[equations[i][0]-'a'].push_back(equations[i][3]-'a');
              adj[equations[i][3]-'a'].push_back(equations[i][0]-'a');
            }
        }
          for(int i=0;i<n;i++){
            if(equations[i][1]=='!'){
                bool flag=false;
                vector<int> vis(26);
                dfs(adj,equations[i][0]-'a', equations[i][3]-'a',flag,vis);
                if(flag){
                  return false;
              }
            }
        }
        return true;
    }
};