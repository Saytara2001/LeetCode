class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int dis = n;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                dis = min({dis, abs(i - startIndex), n - abs(i - startIndex)});
            }
        }
        return dis == n ? -1 : dis;
    }
};