#include <bits/stdc++.h>
using namespace std;

int solve(int i, int k, vector<int>& height, vector<int>& dp) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];

    int ans = INT_MAX;

    for (int j = 1; j <= k; j++) {
        if (i - j >= 0) {
            int jump = solve(i - j, k, height, dp) 
                       + abs(height[i] - height[i - j]);
            ans = min(ans, jump);
        }
    }

    return dp[i] = ans;
}

int frogJumpK(int n, int k, vector<int>& height) {
    vector<int> dp(n, -1);
    return solve(n - 1, k, height, dp);
}

int main() {
    int n = 5, k = 3;
    vector<int> height = {10, 30, 40, 50, 20};

    cout << frogJumpK(n, k, height);
    return 0;
}
