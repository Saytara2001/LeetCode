struct FenwickTree {
    int N;
    vector<int> bit;
    void init(int n) {
        N = n + 5;
        bit.resize(N);
    }
    void add(int idx, int val) {
        while (idx < N) {
            bit[idx] += val; //change here
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int ret = 0;
        while (idx > 0) {
            ret += bit[idx]; //change here
            idx -= idx & -idx;
        }
        return ret;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = size(nums1);
        FenwickTree treeL, treeR;
        treeL.init(n);
        treeR.init(n);
        vector<int> pos(n), reversedIndexMap(n);
        for (int i = 0; i < n; ++i) {
            pos[nums2[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            reversedIndexMap[pos[nums1[i]]] = i; // give the index of nums2 in nums1
        }
        vector<int> left(n), right(n);
        for (int i = 0; i < n; ++i) { // loop on values in nums2
            int idx = reversedIndexMap[i] + 1; // give me the index of nums2 in nums1
            left[i] = treeL.query(idx - 1);
            treeL.add(idx, 1);
        }
        for (int i = n - 1; i >= 0; --i) { // loop on values in nums2
            int idx = reversedIndexMap[i] + 1; // give me the index of nums2 in nums1
            int total = treeR.query(n);
            right[i] = total - treeR.query(idx - 1);
            treeR.add(idx, 1);
        }
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res += 1LL * left[i] * right[i];
        }
        return res;
    }
};