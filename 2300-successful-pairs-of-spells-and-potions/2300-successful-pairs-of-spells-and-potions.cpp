class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(begin(potions), end(potions));
        vector<int> res;
        int n = potions.size();
        for(int i = 0; i < spells.size(); i++) {
            long long need = (success + spells[i] - 1) / spells[i];
            int l = 0, r = n;
            while(l < r) {
                int mid = (l+r)/2;
                if(potions[mid] >= need)
                    r = mid;
                else
                    l = mid + 1;
            } 
            res.push_back(n - l);
        }
        return res;
    }
};