class Solution {
    int dirs[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> outdegree(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (auto& dir : dirs) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n
                        && matrix[ni][nj] < matrix[i][j]) {
                            outdegree[i][j]++;
                        }
                }
                if (outdegree[i][j] == 0) {q.push({i, j});}
            }
        }

        vector<vector<int>> dp(m, vector<int>(n, 1));
        int res = 1;
        
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (auto& dir : dirs) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                res = max(res, dp[i][j]);
                if (ni >= 0 && ni < m && nj >= 0 && nj < n
                    && matrix[ni][nj] > matrix[i][j]) {
                        dp[ni][nj] = max(dp[ni][nj], dp[i][j] + 1);
                        outdegree[ni][nj]--;
                        if (outdegree[ni][nj] == 0) {
                            q.push({ni, nj});
                        }
                }
            }
        }

        return res;
    }
};