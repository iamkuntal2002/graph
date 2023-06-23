#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-height-trees/
// A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

// Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

// Return a list of all MHTs' root labels. You can return the answer in any order.

// The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> adj[n+1];
        vector<int> inorder(n+1);
        queue<int> qu;
        vector<int> res;
        for(auto &ed : edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
            inorder[ed[0]]++;
            inorder[ed[1]]++;
        }
        for(int i =0;i<n;i++){
            if(inorder[i] ==1) qu.push(i);
        }
        while(n>2){
            int size = qu.size();
            n -= size;
            for(int i =0;i<size;i++){
                int node = qu.front();
                qu.pop();
                for(auto adjnode : adj[node]){
                    inorder[adjnode]--;
                    if(inorder[adjnode] == 1) qu.push(adjnode);
                }
            }
        }
        while(!qu.empty()){
            res.push_back(qu.front());
            qu.pop();
        }
        return res;
    }
};