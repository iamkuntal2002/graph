#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  void dfs(vector<vector<int>>& grid,int m,int n,int i,int j,int x0, int y0, vector<pair<int,int>> &st){
      if(i<0 || j<0 || i>= m || j>= n || grid[i][j] ==0) return;
      st.push_back({i-x0,j-y0});
      grid[i][j] = 0;
      dfs(grid,m,n,i,j+1,x0,y0,st);
      dfs(grid,m,n,i,j-1,x0,y0,st);
      dfs(grid,m,n,i+1,j,x0,y0,st);
      dfs(grid,m,n,i-1,j,x0,y0,st);
      
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        set<vector<pair<int,int>>> st;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == 1){
                    vector<pair<int,int>> temp;
                    dfs(grid,m,n,i,j,i,j,temp);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
};
int main() {

}