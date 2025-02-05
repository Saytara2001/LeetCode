class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        vector<int> pos;
        int n = size(s1);

        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i])
             pos.push_back(i);
        }

        if(pos.size() == 2) 
            swap(s1[pos[0]], s1[pos[1]]);

        return s1 == s2;
    }
};