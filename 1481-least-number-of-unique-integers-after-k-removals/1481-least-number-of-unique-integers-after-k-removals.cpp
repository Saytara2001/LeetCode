class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto it: arr) {
            mp[it]++;
        }
        vector<int> freq;
        for(auto it: mp) {
            freq.push_back(it.second);
        }
        sort(begin(freq), end(freq));
        for(int i = 0; i < size(freq); i++) {
            if(k >= freq[i]) {
                k -= freq[i];
            }else {
                return size(freq) - i;
            }
        }
        return 0;
    }
};