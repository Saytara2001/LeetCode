class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(begin(potions), end(potions));
        vector<int> res;
        int n = potions.size();
        int maxPotion = potions.back();
        for(int i = 0; i < spells.size(); i++) {
            long long need = (success + spells[i] - 1) / spells[i];
           if(need > maxPotion) {
               res.push_back(0);
               continue;
           }
            int idx = lower_bound(potions.begin(), potions.end(), need) - potions.begin();
            res.push_back(n - idx);  
        }
        return res;
    }
};