#include <bits/stdc++.h>
using namespace std;

int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
  if (day == 0)
  {
    int ma = 0;
    for (int i = 0; i < 3; i++)
    {
      if (i != last)
      {
        ma = max(ma, points[0][i]);
      }
    }
    return ma;
  }
  if (dp[day][last] != -1)
    return dp[day][last];
  int ma = 0;
  for (int i = 0; i < 3; i++)
  {
    if (i != last)
    {
      int po = points[day][i] + f(day - 1, i, points, dp);
      ma = max(ma, po);
    }
  }
  return dp[day][last] = ma;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
 
  vector<vector<int>> dp(n + 1, vector<int>(4, -1));
  return f(n - 1, 3, points, dp);
}
int main()
{
}