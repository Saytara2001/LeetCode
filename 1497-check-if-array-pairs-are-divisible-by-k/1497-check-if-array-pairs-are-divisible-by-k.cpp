class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        int n = size(arr);
        map<int, int> mp;
        
        for(int i = 0; i < n ; i++) {
            arr[i] = ((arr[i] % k) + k) % k;
            mp[arr[i]]++;
        }
        
        int pairs = 0;
        for(int i = 0; i < n ; i++) {
            if(mp[arr[i]] > 0) {
                mp[arr[i]]--;
                int need = (((k - arr[i]) % k) + k) % k;
                if(--mp[need] >= 0)
                    ++pairs;
            }
        }
        
        return pairs == n / 2;
    }
};