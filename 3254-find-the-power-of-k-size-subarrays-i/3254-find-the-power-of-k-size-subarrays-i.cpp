class Solution {
public:
    vector<int> resultsArray(vector<int>& v, int k) {
        
        int l = 0, r = 0, n = size(v);
        vector<int> res(n - k + 1, -1);
        while(r < n) {
            if(v[l] + (r - l) == v[r]) {
                if(r - l + 1 == k) 
                    res[l++] = v[r];
                ++r;
            }else {
               l = r;
            }
            
        }
        
        return res;
    }
};