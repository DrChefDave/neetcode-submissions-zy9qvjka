class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
         
        unordered_map<int, vector<char>> mup;
        int n = 2 * numRows - 2;

        for (int i = 0; i < s.size(); i++) {
            int row = ((i % n) < numRows) ? (i % n) : n - (i % n) ;
            mup[row].push_back(s[i]);
        }

        string result = "";
        for (int i = 0; i < numRows; i++) {
            string t(mup[i].begin(), mup[i].end());
            result += t;
        }
        return result;
    }
};