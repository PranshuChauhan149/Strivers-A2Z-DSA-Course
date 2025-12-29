#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool f(vector<int> &arr, int sum, int i, vector<vector<int>> &dp)
  {
    int n = arr.size();
    if (sum < 0)
      return false;
    if (sum == 0)
      return true;
    if (i == n - 1)
    {
      if (sum - arr[i] == 0)
      {
        return true;
      }
      else
        return false;
    }
    if (dp[i][sum] != -1)
      return dp[i][sum];

    bool np = f(arr, sum, i + 1, dp);
    bool p = f(arr, sum - arr[i], i + 1, dp);

    return dp[i][sum] = (np || p);
  }

  bool isSubsetSum(vector<int> &arr, int sum)
  {
    vector<vector<int>> dp(arr.size() + 1, vector<int>(sum + 1, -1));
    return f(arr, sum, 0, dp);
  }
};
int main()
{
}