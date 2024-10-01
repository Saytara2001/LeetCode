class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        int n = size(arr);
        map<int, int> mp;
        
        for(int i = 0; i < n ; i++) {
            arr[i] = ((arr[i] % k) + k) % k;
            mp[arr[i]]++;
        }
        
        for(int i = 0; i < n ; i++) {
            int need = ((k - arr[i]) % k + k) % k;
            if(mp[arr[i]]) {
                 mp[arr[i]]--;
                if(--mp[need] < 0)
                    return false;
            }
        }
        
        return true;
    }
};