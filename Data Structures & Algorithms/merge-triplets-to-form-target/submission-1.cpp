class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> test = {0,0,0};
        vector<int> dumm = triplets[0];
        
        for (auto trip : triplets) {
            int i = 0;
            while (i < 3) {
                if (trip[i] > target[i]) {
                    break;
                } else {
                    dumm[i] = max(test[i], trip[i]);
                }
                i++;
            }
            if (i == 3) {test = dumm;}
        }

        return (target == test) ? true : false;
    }
};
