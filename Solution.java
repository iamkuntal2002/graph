// import java.util.Arrays;

// public class Solution{
//     public static boolean isboundary(int i,int j,int n,int m){
//         if(i==0 || j== 0 || i == n-1 || j == m-1) return true;
//         return false;
//     }
//     public static void dfs(char matrix[][],int i,int j,vector<vector<bool>> &vis){
//         if(i<0 || j<0 || i>= matrix.length || j>= matrix[0].length || matrix[i][j] == 'X' || vis[i][j]) return;
//         vis[i][j] = true;
//         dfs(matrix,i+1,j,vis);
//         dfs(matrix,i-1,j,vis);
//         dfs(matrix,i,j+1,vis);
//         dfs(matrix,i,j-1,vis);
//     }
//     public static void replaceOWithX(char matrix[][]) {
//         // write your code here
//         int n = matrix.length;
//         int m = matrix[0].length;
//         // vector<vector<bool>> vis(n,vector<bool>(m,false));
//         boolean vis[][] = new boolean[n][m]
//         // Arrays.fill(vis,false);
//         Arrays.fill(vis, false);
//         for(int i =0;i<n;i++){
//             for(int j =0;j<m;j++){
//                 if(isboundary(i,j,n,m) && matrix[i][j] =='O') dfs(matrix,i,j,vis);
//             }
//         }
//         for(int i =0;i<n;i++){
//             for(int j =0;j<m;j++){
//                 if(mat[i][j] == 'O' && !vis[i][j]) mat[i][j] = 'X';
//             }
//         }
//         return mat;
//     }

// }