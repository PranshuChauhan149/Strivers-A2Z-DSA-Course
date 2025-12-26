#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
  vector<vector<int>> dp;
  int f(vector<vector<int>> &grid, int i, int j)
  {
    int r = grid.size();
    int c = grid[0].size();

    if (i < 0 || i >= r || j < 0 || j >= c)
      return INT_MAX;
    if (i == r - 1 && j == c - 1)
      return grid[i][j];

    if (dp[i][j] != -1)
      return dp[i][j];

    int right = f(grid, i, j + 1);
    int down = f(grid, i + 1, j);

    return dp[i][j] = grid[i][j] + min(right, down);
  }
  int minPathSum(vector<vector<int>> &grid)
  {
    int r = grid.size();
    int c = grid[0].size();
    dp.assign(r, vector<int>(c, -1));
    return f(grid, 0, 0);
  }
};
int main()
{
}