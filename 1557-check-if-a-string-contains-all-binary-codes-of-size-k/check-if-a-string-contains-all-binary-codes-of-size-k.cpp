class Solution {
public:
    bool hasAllCodes(string s, int k) {
        string gen = "";
        int n = s.size();
        set<string> all;
        for (int i = 0; i < n; i++) {
            gen += s[i];

            if (gen.size() > k)
                gen.erase(gen.begin());

            if (gen.size() == k) {
                all.insert(gen);
            }
        }
        return all.size() == (1 << k);
    }
};