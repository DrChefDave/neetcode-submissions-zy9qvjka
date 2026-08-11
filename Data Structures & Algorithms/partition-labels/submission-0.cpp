class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mup(26);
        int state = 0;

        vector<int> res;
        int l = 0;
        for (char c : s) mup[c - 'a']++;

        for (int i = 0 ; i < s.length(); i++) {
            char c = s[i];
            int mask = 1 << (c - 'a');
            state |= mask;
            mup[c - 'a']--;
            
            if (mup[c - 'a'] == 0) state ^= mask; // Remove from state


            if (!state) {
                res.push_back(i-l+1);
                l = i+1;
            }
        }

        return res;

    }
};
