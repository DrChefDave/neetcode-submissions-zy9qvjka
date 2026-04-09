class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int targ = 0;
        for (int num : nums) targ += num;
        if (targ % 2) return false;
        targ /= 2;

        unordered_set<int> dp;
        dp.insert(0);

        for (int num : nums) {
            unordered_set<int> dp2;
            for (int t : dp) {
                if(t + num == targ) return true;

                dp2.insert(t + num);
                dp2.insert(t);
            }

            dp = dp2;
        }

        return false;

    }
};
