class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int n = size(s);
        int groups = (n + k - 1) / k;
        for(int i = 0; i < groups; i++) {
            string t = "";
            for(int j = 0; j < k; j++) 
                if(i * k + j < n)
                    t.push_back(s[i * k + j]);
                else
                    t.push_back(fill);
            
            res.push_back(t);
        }

        return res;
    }
};