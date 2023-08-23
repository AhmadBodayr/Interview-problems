// leetcode 322. Coin Change
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = (int) coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for(int i = 1; i <= amount; i++) {
            if(i % coins[0] == 0) dp[0][i] = i / coins[0];
            else dp[0][i] = -1;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];
                if(coins[i] <= j && dp[i][j - coins[i]] != -1) {
                    if(dp[i][j] == -1) dp[i][j] = 1 + dp[i][j - coins[i]];
                    else dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i]]);
                }
            }
        }
        return dp[n - 1][amount];
    }
};