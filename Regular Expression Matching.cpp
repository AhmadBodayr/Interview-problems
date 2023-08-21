// leetcode problem
using namespace std;
#include <bits/stdc++.h>
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = (int) p.size(), m = (int) s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            if(i == n) {
                if(p[i - 1] == '*') dp[i][0] = 1;
            } else {
                if(p[i] == '*') dp[i][0] = 1;
                else if(p[i - 1] == '*') dp[i][0] = 1;
                else break;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(p[i - 1] == '*') {
                for(int j = 0; j <= m; j++) dp[i][j] = dp[i - 1][j];
                continue;
            }
            if(i == n) {
                if(p[i - 1] == '.') {
                    for(int j = 1; j <= m; j++) if(dp[i - 1][j - 1]) {
                        dp[i][j] = 1;
                    } 
                } else {
                    for(int j = 1; j <= m; j++) {
                        if(dp[i - 1][j - 1] && p[i - 1] == s[j - 1]) {
                            dp[i][j] = 1;
                        }
                    }
                }
            } else { // The problem
                if(p[i] == '*') {
                    if(p[i - 1] == '.') {
                        for(int j = 1; j <= m; j++) {
                            dp[i][j] = dp[i - 1][j] | dp[i][j - 1] | dp[i - 1][j - 1];
                        }
                    } else {
                        for(int j = 1; j <= m; j++) {
                            dp[i][j] = dp[i - 1][j];
                            if(p[i - 1] == s[j - 1]) {
                                if(dp[i - 1][j - 1] || dp[i][j - 1]) {
                                    dp[i][j] = 1;
                                }
                            }
                        }
                    }
                } else {
                    if(p[i - 1] == '.') {
                        for(int j = 1; j <= m; j++) if(dp[i - 1][j - 1]) {
                            dp[i][j] = 1;
                        }
                    } else {
                        for(int j = 1; j <= m; j++) {
                            if(dp[i - 1][j - 1] && p[i - 1] == s[j - 1]) {
                                dp[i][j] = 1;
                            }
                        } 
                    }
                }
            }
        }
        return dp[n][m];
    }
};