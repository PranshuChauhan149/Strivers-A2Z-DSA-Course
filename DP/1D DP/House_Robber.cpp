#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int f(vector<int> &nums, int i, vector<int> &dp)
  {
    int n = nums.size();
    if (i == n - 1)
    {
      return nums[i];
    }
    if (i == n - 2)
      return max(nums[i], nums[i + 1]);
    if (dp[i] != -1)
      return dp[i];
    int notPick = 0 + f(nums, i + 1, dp);
    int pick = nums[i] + f(nums, i + 2, dp);

    return dp[i] = max(pick, notPick);
  }

  int rob(vector<int> &nums)
  {
    vector<int> dp(nums.size() + 1, -1);
    return f(nums, 0, dp);
  }
};
int main()
{
}