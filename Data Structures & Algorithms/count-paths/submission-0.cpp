class Solution {
public:
    int uniquePaths(int m, int n) {
        // Pascal's Triangle Approach
        if (m == 1 || n == 1) return 1;
        int pascal[m][n];

        for (int i = 0; i < n; i++) {pascal[0][i] = 1;}
        for (int i = 0; i < m; i++) {pascal[i][0] = 1;}

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                pascal[i][j] = pascal[i-1][j] + pascal[i][j-1];
            }
        }

        return pascal[m-1][n-1];

    }
};
