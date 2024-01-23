class Solution {
public:
    int rec(int i, vector<string>& arr, string s) {
        if(i == size(arr)) {
            vector<bool> freq(26, 0);
            for(auto it: s) {
                if(freq[it - 'a']) return 0;
                freq[it - 'a'] = true;
            }
            return size(s);
        }
        int mx = rec(i + 1, arr, s);
        mx = max(mx, rec(i + 1, arr, s + arr[i]));
        return mx;
    }
    int maxLength(vector<string>& arr) {
        return rec(0, arr, "");
    }
};