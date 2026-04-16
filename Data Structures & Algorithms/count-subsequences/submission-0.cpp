class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<int> dp(n+1, 0);
        vector<int> temp(n+1, 0);
        dp[0] = temp[0] = 1;
        for (int i = 0; i <= m; i++) {
            
            for (int j = 0; j <= n; j++) {
                temp[j] = dp[j];
                if (s[i-1] == t[j-1]) {
                    temp[j] += dp[j - 1];
                }
            }

            dp = temp;
        }

        return dp[n];
    }
};
