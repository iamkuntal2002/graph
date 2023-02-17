#include <bits/stdc++.h>
using namespace std;
// bool isvalid(int n,int m,int i,int j,vector<vector<bool>>& vis){
//     // if(i<0 || i>=n || j<0 || j>= m || vis[i][j] == true) return false;
//     // return true;
//     if(i<0 ||j<0||i>=n||j>=m||vis[i][j]== true) return false;
//     return true;
// }
void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j, int n, int m)
{
    // vis[i][j] = true;
    // if(isvalid(n,m,i+1,j,vis) && grid[i+1][j] == '1') dfs(grid,vis,i+1,j,n,m);
    // if(isvalid(n,m,i-1,j,vis) && grid[i-1][j] == '1') dfs(grid,vis,i-1,j,n,m);
    // if(isvalid(n,m,i,j+1,vis) && grid[i][j+1] == '1') dfs(grid,vis,i,j+1,n,m);
    // if(isvalid(n,m,i,j-1,vis) && grid[i][j-1] == '1') dfs(grid,vis,i,j-1,n,m);
    // if(isvalid(n,m,i+1,j+1,vis) && grid[i+1][j+1] == '1') dfs(grid,vis,i+1,j+1,n,m);
    // if(isvalid(n,m,i+1,j-1,vis) && grid[i+1][j-1] == '1') dfs(grid,vis,i+1,j-1,n,m);
    // if(isvalid(n,m,i-1,j+1,vis) && grid[i-1][j+1] == '1') dfs(grid,vis,i-1,j+1,n,m);
    // if(isvalid(n,m,i-1,j-11,vis) && grid[i-1][j-1] == '1') dfs(grid,vis,i-1,j-1,n,m);

    if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] == true || grid[i][j] == '0')
        return;
    vis[i][j] = true;
    dfs(grid, vis, i + 1, j, n, m);
    dfs(grid, vis, i - 1, j, n, m);
    dfs(grid, vis, i, j + 1, n, m);
    dfs(grid, vis, i, j - 1, n, m);
    dfs(grid, vis, i + 1, j + 1, n, m);
    dfs(grid, vis, i + 1, j - 1, n, m);
    dfs(grid, vis, i - 1, j + 1, n, m);
    dfs(grid, vis, i - 1, j - 1, n, m);
}
int numIslands(vector<vector<char>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' && !vis[i][j])
            {
                count++;
                dfs(grid, vis, i, j, n, m);
            }
        }
    }
    return count;
}
int main(){
    
}