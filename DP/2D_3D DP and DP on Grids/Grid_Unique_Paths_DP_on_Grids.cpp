#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int f(int a, int b, int i, int j, vector<vector<int>> &dp)
  {
    if (i == a - 1 && j == b - 1)
    {
      return 1;
    }
    if (i < 0 || i >= a || j < 0 || j >= b)
    {
      return 0;
    }
    if (dp[i][j] != -1)
      return dp[i][j];
    int down = f(a, b, i + 1, j, dp);
    int right = f(a, b, i, j + 1, dp);
    return dp[i][j] = (down + right);
  }
  int NumberOfPath(int a, int b)
  {
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));
    return f(a, b, 0, 0, dp);
  }
};

int main()
{
}