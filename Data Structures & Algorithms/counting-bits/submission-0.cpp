class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++) res.push_back(count(i));
        return res;
    }

    int count(int n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res += (n & 1) ? 1 : 0;
            n >>= 1;
        }
        return res;
    }
};
