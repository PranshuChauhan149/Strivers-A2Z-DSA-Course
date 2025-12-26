#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int f(vector<int> &nums, int i, int n, vector<int> &dp)
  {
    if (i == n - 1)
      return nums[i];
    if (i == n - 2)
      return max(nums[i], nums[i + 1]);
    if (dp[i] != -1)
      return dp[i];
    int np = 0 + f(nums, i + 1, n, dp);
    int p = nums[i] + f(nums, i + 2, n, dp);
    return dp[i] = max(np, p);
  }

  int rob(vector<int> &nums)
  {

    int n = nums.size();
    if (n == 1)
      return nums[0];
    if (n == 2)
      return max(nums[0], nums[1]);
    vector<int> dp(n + 1, -1);
    int a = f(nums, 0, n - 1, dp);
    dp.assign(n + 1, -1);
    int b = f(nums, 1, n, dp);
    return max(a, b);
  }
};
int main()
{
}