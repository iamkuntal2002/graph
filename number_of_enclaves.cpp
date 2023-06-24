#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/number-of-enclaves/1

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>> &grid,int i,int j,int m,int n,int &curr){
        if(i<0 || j<0 || i>= m || j>= n || grid[i][j] ==0) return ;
        // int ans =0;
       
        if(grid[i][j] == 1) curr++;
        grid[i][j] = 0;
        dfs(grid,i,j+1,m,n,curr);
        dfs(grid,i,j-1,m,n,curr);
        dfs(grid,i+1,j,m,n,curr);
        dfs(grid,i-1,j,m,n,curr);
    }
    bool isside(int i,int j,int m,int n){
        if(i == 0 | j == 0 || i == m-1 || j == n-1) return true;
        return false;
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(isside(i,j,m,n) && grid[i][j] == 1){
                    int temp =0;
                    dfs(grid,i,j,m,n,temp);
                }
            }
        }
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == 1){
                    // int curr = 0;
                    ans++;
                    // dfs(grid,i,j,m,n,curr);
                    // ans = max(ans,curr);
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends