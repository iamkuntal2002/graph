#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
class Solution {
public:
    void getInd(vector<int> adj[],vector<int> &ind,int n){
        for(int i =0;i<n;i++){
            for(int node : adj[i]){
                ind[node]++;
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> adj[n+1];
        for(auto ed : edges){
            adj[ed[0]].push_back(ed[1]);
        }
        vector<int> ind(n,0);
        getInd(adj,ind,n);
        vector<int> res;
        for(int i =0;i<n;i++){
            if(ind[i] == 0) res.push_back(i);
        }
        return res;
    }
};

// 0 : 1,2
// 1 : 
// 2 : 5
// 3 : 4
// 4 : 2
// 5 :  