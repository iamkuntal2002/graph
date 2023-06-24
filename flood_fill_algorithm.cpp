#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
void helper(vector<vector<int>> &image, int sr, int sc, int color, int row, int col, int source)
{
    if (sr < 0 || sc < 0 || sr >= row || sc >= col)
        return;
    else if (image[sr][sc] != source)
        return;
    image[sr][sc] = color;
    helper(image, sr - 1, sc, color, row, col, source);
    helper(image, sr + 1, sc, color, row, col, source);
    helper(image, sr, sc - 1, color, row, col, source);
    helper(image, sr, sc + 1, color, row, col, source);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    // Code here
    // if(image[sr][sc] )
    if (newColor == image[sr][sc])
        return image;
    int m = image.size();
    int n = image[0].size();
    int source = image[sr][sc];
    helper(image, sr, sc, newColor, m, n, source);
    return image;
}
int main()
{
}