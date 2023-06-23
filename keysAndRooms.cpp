#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/keys-and-rooms
//we try to reach all nodes from node 0, and at the end we chech if any node wasn't reached, if not then return false
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n,false);
        queue<int> qu;
        qu.push(0);
        vis[0] = true;
        while(!qu.empty()){
            int room = qu.front();
            qu.pop();
            for(int e : rooms[room]){
                if(!vis[e]){
                    vis[e] =  true;
                    qu.push(e);
                }
            }    
        }
        for(bool reach : vis){
            if(!reach) return false;
        }
        return true;
    }
};