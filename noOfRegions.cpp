#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/regions-cut-by-slashes/
class Solution {
public:
    void helper(int i,int j,int size,vector<vector<int>>&vec){
        if(i<0 || i>=size ||j<0 ||j>=size || vec[i][j]==1) return;
        vec[i][j]=1;
        helper(i-1,j,size,vec);
        helper(i+1,j,size,vec);
        helper(i,j-1,size,vec);
        helper(i,j+1,size,vec);
    }
    void print(vector<vector<int>> &vec){
        for(auto v : vec){
            for(auto el : v){
                cout<<el<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    int regionsBySlashes(vector<string>& grid) {
        int n= grid.size();
        vector<vector<int>> vec(3*n,vector<int>(3*n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int xc=3*j;
                int yc=3*i;
                if(grid[i][j]=='/'){
                    vec[yc][xc+2]=1;
                    vec[yc+1][xc+1]=1;
                    vec[yc+2][xc]=1;
                }
                else if(grid[i][j]=='\\'){
                    vec[yc][xc]=1;
                    vec[yc+1][xc+1]=1;
                    vec[yc+2][xc+2]=1;
                }
            }
        }
        print(vec);
        int res=0;
        for(int i=0;i<3*n;i++){
            for(int j=0;j<3*n;j++){
                if(vec[i][j]==0){
                    res++;
                    helper(i,j,3*n,vec);
                }
            }
        }
        return res;
    }
};
int main(){
    vector<string> v = {"/\\","\\/"};
    Solution sol;
    sol.regionsBySlashes(v);
}