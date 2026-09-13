class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i-1]) {continue;}
            int target = 0 - nums[i];
            int l = i + 1, r = nums.size() - 1;

            while (l < r) {
                int curs = nums[l] + nums[r];
                if (curs < target) {l++;}
                else if (curs > target) {r--;}
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (l < r && nums[l] == nums[l-1]) {l++;}
                    }
            }

        }

        return res;

    }
};
