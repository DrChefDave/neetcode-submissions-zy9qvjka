class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int state = 0;
        for (int num : nums) {
            state ^= num;
        }
        return state;

    }
};
