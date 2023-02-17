#include <bits/stdc++.h>
using namespace std;
bool isvalid(int &m, int &n, int &nx, int &ny)
{
    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
        return false;
    return true;
}
// Function to find distance of nearest 1 in the grid for each cell.
vector<vector<int>> nearest(vector<vector<int>> grid)
{
    // Code here
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<pair<int, int>, int>> qu; // i,j,dist
    vector<vector<int>> vis(m, vector<int>(n, 0));
    vector<vector<int>> res(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                qu.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    while (!qu.empty())
    {
        auto pr = qu.front();
        qu.pop();
        int x = pr.first.first;
        int y = pr.first.second;
        int dist = pr.second;
        res[x][y] = dist;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isvalid(m, n, nx, ny) && vis[nx][ny] == 0)
            {
                vis[nx][ny] = 1;
                qu.push({{nx, ny}, dist + 1});
            }
        }
    }
    return res;
}
int main()
{
}