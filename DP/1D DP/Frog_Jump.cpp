#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int f(vector<int> &height, int i, vector<int> &dp)
  {
    if (i == height.size() - 1)
    {
      return 0;
    }
    if (dp[i] != -1)
      return dp[i];
    int np = INT_MAX;
    int p = abs(height[i] - height[i + 1]) + f(height, i + 1, dp);
    if (i + 2 < height.size())
    {

      np = abs(height[i] - height[i + 2]) + f(height, i + 2, dp);
    }
    return dp[i] = min(p, np);
  }

  int minCost(vector<int> &height)
  {
    int n = height.size();

    if (n == 1)
      return 0;
    if (n == 2)
      return abs(height[0] - height[1]);
    vector<int> dp(n + 1, -1);
    return f(height, 0, dp);
  }
};

int main()
{
}