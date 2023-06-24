#include <bits/stdc++.h>
using namespace std;
bool ispossible(int n,int m,int i,int j){
    if(i<0 || j<0 || i>=n || j>=m) return false;
    return true;
}
void dfs(int** arr,vector<vector<bool>> &vis,vector<pair<int,int>> &temp,int i,int j,int n,int m,int i0,int j0){
    vis[i][j] = true;
    temp.push_back({i-i0,j-j0});
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    for(int i =0;i<4;i++){
        int ni = i+dx[i];
        int nj = j+dy[i];
        if(ispossible(n,m,ni,nj) && !vis[ni][nj] && arr[ni][nj] == 1)
            dfs(arr,vis,temp,ni,nj,n,m,i0,j0);
    }
}

int distinctIslands(int** arr, int n, int m)
{
    //Write your code here
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    set<vector<pair<int,int>>> st;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(!vis[i][j] && arr[i][j] == 1){
                vector<pair<int,int>> temp;
                dfs(arr,vis,temp,i,j,n,m,i,j);
                st.insert(temp);
            }
        }
    }
    return st.size();
}