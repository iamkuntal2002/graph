#include<bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/find-number-of-closed-islands/1
class Solution {
    public:
    bool isvalid(vector<vector<int>> &mat, int i,int j, int n, int m){
        if(i<0 || j< 0 || i>= n || j>= m || mat[i][j] == 0) return false;
        return true;
    }
    void dfs(vector<vector<int>> &mat, int i,int j,int n,int m){
        // if(isvalid(mat,i,j,n,m)) return;
        if(i<0 || j< 0 || i>= n || j>= m || mat[i][j] == 0) return ;
        mat[i][j] = 0;
        dfs(mat,i,j+1,n,m);
        dfs(mat,i,j-1,n,m);
        dfs(mat,i+1,j,n,m);
        dfs(mat,i-1,j,n,m);
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        //make all the 1's to 0 which are present at the edge of the matrix and perfrom dfs on them
        for(int i =0;i<N;i++){
            for(int j =0;j<M;j++){
                if(i ==0 || j ==0 || i == N-1 || j == M-1 && matrix[i][j] ==1)
                    dfs(matrix,i,j,N,M);
            }
        }
        int count =0;
        //now again perform dfs to count the no of islands
        for(int i =0;i<N;i++){
            for(int j =0;j<M;j++){
                if( matrix[i][j] == 1){
                    count++;
                    dfs(matrix,i,j,N,M);
                }
            }
        }
        return count;
    }
};
int main() {
		
}
