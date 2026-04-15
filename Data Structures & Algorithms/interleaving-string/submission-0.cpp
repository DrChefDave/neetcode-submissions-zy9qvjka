class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                int k = i + j;
                
                if (i > 0) {
                    dp[i][j] = dp[i][j] || 
                              (dp[i-1][j] && s1[i-1] == s3[k-1]);
                }

                if (j > 0) {
                    dp[i][j] = dp[i][j] || 
                              (dp[i][j-1] && s2[j-1] == s3[k-1]);
                }
            }
        }

        return dp[s1.length()][s2.length()];
    }
};

//       a  a  a  a
//   [T][T][T][F][F]
// b [F][F][T][F][F]
// b [-][-][T][-][-]
// b [-][-][T][-][-]
// b [-][-][T][T][T]