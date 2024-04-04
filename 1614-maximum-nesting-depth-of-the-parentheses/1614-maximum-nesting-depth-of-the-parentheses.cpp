class Solution {
public:
    int maxDepth(string s) {
        int open = 0, maxDepth = 0;
        for(auto it: s) {
            open += (it == '(');
            open -= (it == ')');
            maxDepth = max(maxDepth, open);
        }
        return maxDepth;
    }
};