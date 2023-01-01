#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    bool isvalid(vector<vector<int>>& grid,int x,int y){
        if(x<0 || y<0 || x>= grid.size() || y >= grid[0].size()) return false;
        return true;
    }
    void bfs(vector<vector<int>>& grid,queue<pair<pair<int,int>,int>> &qu,int &res,int x[],int y[]){
        while(!qu.empty()){
            int i = qu.front().first.first;
            int j = qu.front().first.second;
            int time = qu.front().second;
            qu.pop();
            res = max(res,time);
            for(int it = 0;it<4;it++){
                int nx = i+x[it];
                int ny = j+y[it];
                if(isvalid(grid,nx,ny) && grid[nx][ny] ==1){
                    grid[nx][ny] = 2;
                    qu.push({{nx,ny},time+1});
                }
            }
        }
    }
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int res = 0;
        queue<pair<pair<int,int>,int>> qu; //i,j,time
        int m = grid.size();
        int n = grid[0].size();
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == 2){
                    qu.push({{i,j},0});
                }
            }
        }
        int x[] = {0,0,1,-1};
        int y[] = {-1,1,0,0};
        bfs(grid,qu,res,x,y);
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return res;
    }
};

int main(){
	
}