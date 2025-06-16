class Solution {
public:
    int maxCandies(vector<int> &hasKey, vector<int> &candies, vector<vector<int>> &keys,
                   vector<vector<int>> &containedBoxes, vector<int> &initialBoxes) {
        int n = size(hasKey);
        vector<bool> hasBox(n), opened(n);
        queue<int> q; // put opened boxes only
        for (int i = 0; i < initialBoxes.size(); ++i) {
            hasBox[initialBoxes[i]] = 1;
            if (hasKey[initialBoxes[i]]) {
                opened[initialBoxes[i]] = 1;
                q.push(initialBoxes[i]);
            }
        }
        // visited box check (TLE)
        int res = 0;
        while (q.size()) {
            int box = q.front();
            q.pop();
            res += candies[box];
            for (int i = 0; i < keys[box].size(); ++i) {
                hasKey[keys[box][i]] = 1; // key found
                if (hasBox[keys[box][i]] and !opened[keys[box][i]]) {
                    q.push(keys[box][i]);
                    opened[keys[box][i]] = 1;
                }
            }
            for (int i = 0; i < containedBoxes[box].size(); ++i) {
                hasBox[containedBoxes[box][i]] = 1; // box found
                if (hasKey[containedBoxes[box][i]] and !opened[containedBoxes[box][i]]) {
                    q.push(containedBoxes[box][i]);
                    opened[containedBoxes[box][i]] = 1;
                }
            }
        }
        return res;
    }
};