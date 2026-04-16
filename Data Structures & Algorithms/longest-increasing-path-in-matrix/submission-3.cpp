class Solution {
    int  dirs[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> outgoing(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (auto& dir : dirs) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n
                     && matrix[ni][nj] < matrix[i][j]) {
                        outgoing[i][j]++;
                    }
                }
                if (!outgoing[i][j]) {q.push({i,j});}
            }
        }

        int res = 1;
        vector<vector<int>> dp(m, vector<int>(n, 1));
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (auto& dir : dirs) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n
                    && matrix[ni][nj] > matrix[i][j]) {
                        dp[ni][nj] = max(dp[i][j] + 1, dp[ni][nj]);
                        res = max(res, dp[ni][nj]);
                        outgoing[ni][nj]--;
                        if (!outgoing[ni][nj]) {q.push({ni,nj});}
                    }
            }
        }
        return res;
    }
};
