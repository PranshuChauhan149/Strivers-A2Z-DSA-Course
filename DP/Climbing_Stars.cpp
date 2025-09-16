#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> dp;
  int f(int n)
  {
    if (n == 1 || n == 2)
      return n;
    if (dp[n] != -1)
      return dp[n];
    return dp[n] = f(n - 1) + f(n - 2);
  }

  int climbStairs(int n)
  {
    dp.clear();
    dp.resize(n + 1, -1);
    return f(n);
  }
};

int main()
{
}