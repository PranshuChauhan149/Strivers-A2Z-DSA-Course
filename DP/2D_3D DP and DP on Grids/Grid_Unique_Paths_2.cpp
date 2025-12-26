#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  const int MOD = 1e9 + 7;
  int f(int n, int m, vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
  {
    if (i == n - 1 && j == m - 1)
    {
      return 1;
    }
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 1)
    {
      return 0;
    }
    if (dp[i][j] != -1)
      return dp[i][j];
    int down = f(n, m, grid, i + 1, j, dp);
    int right = f(n, m, grid, i, j + 1, dp);

    return dp[i][j] = (down + right) % MOD;
  }

  int totalWays(int n, int m, vector<vector<int>> &grid)
  {

    if (grid[n - 1][m - 1] == 1)
      return 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(n, m, grid, 0, 0, dp);
  }
};
int main()
{
}