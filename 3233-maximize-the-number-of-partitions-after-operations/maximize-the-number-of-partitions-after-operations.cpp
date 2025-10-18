#define popcount __builtin_popcount
class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        vector<vector<int> > left(n, vector<int>(2));
        vector<vector<int> > right(n, vector<int>(2));
        int uni = 0, splits = 0, mask = 0;
        for (int i = 0; i < n - 1; ++i) {
            int c = s[i] - 'a';
            int binary = (1 << c);
            if (!(binary & mask)) {
                ++uni;
                if (uni <= k) {
                    mask |= binary;
                } else {
                    ++splits;
                    mask = binary;
                    uni = 1;
                }
            }
            left[i + 1][0] = splits; // how many splits are left me
            left[i + 1][1] = mask; // mask of last split
        }
        splits = 0, mask = 0, uni = 0;
        for (int i = n - 1; i > 0; --i) {
            int c = s[i] - 'a';
            int binary = (1 << c);
            if (!(binary & mask)) {
                ++uni;
                if (uni <= k) {
                    mask |= binary;
                } else {
                    ++splits;
                    mask = binary;
                    uni = 1;
                }
            }
            right[i - 1][0] = splits;
            right[i - 1][1] = mask;
        }
        int maxPartitions = 0;
        for (int i = 0; i < n; ++i) {
            int seg = left[i][0] + right[i][0] + 2;
            int mask = left[i][1] | right[i][1];
            int uni = popcount(mask);
            int leftUni = popcount(left[i][1]);
            int rightUni = popcount(right[i][1]);
            if (leftUni == k and rightUni == k and uni < 26) {
                ++seg;
            } else if (min(uni + 1, 26) <= k) {
                --seg;
            } 
            maxPartitions = max(maxPartitions, seg);
        }
        return maxPartitions;
    }
};