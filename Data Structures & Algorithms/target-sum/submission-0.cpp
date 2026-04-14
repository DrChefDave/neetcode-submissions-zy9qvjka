class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp(nums.size() + 1);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> temp;
            for (auto& p : dp) {
                temp[p.first + nums[i]] += p.second;
                temp[p.first - nums[i]] += p.second;
            }
            dp = temp;
        }

        return dp[target];
    }
};
